/* 简化版字谜游戏（保留设计思路）
 * - 使用静态题库构造字符网格
 * - 支持按行或按列选择题目
 * - 支持单字母或整词猜测，显示掩码和剩余机会
 * 目的：方便在课堂/练习中演示按行/列遍历与字符串拼接的用法
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

const char *riddles[] = {"this", "two", "fat", "that"};
const int RIDDLE_COUNT = sizeof(riddles) / sizeof(riddles[0]);

/* 计算数组中最长字符串长度 */
int max_length_in_array(const char **arr, int n) {
    int max = 0;
    for (int i = 0; i < n; ++i) {
        int len = (int)strlen(arr[i]);
        if (len > max) max = len;
    }
    return max;
}

/* 去除字符串右侧空格（原地修改） */
void rtrim(char *s) {
    int n = (int)strlen(s);
    while (n > 0 && isspace((unsigned char)s[n-1])) { s[n-1] = '\0'; n--; }
}

/* 提取指定行到 out（已以 \0 结尾） */
void extract_row(char grid[][64], int cols, int r, char *out) {
    for (int j = 0; j < cols; ++j) out[j] = grid[r][j];
    out[cols] = '\0';
    rtrim(out);
}

/* 提取指定列到 out（已以 \0 结尾） */
void extract_col(char grid[][64], int rows, int c, char *out) {
    int p = 0;
    for (int i = 0; i < rows; ++i) out[p++] = grid[i][c];
    out[p] = '\0';
    rtrim(out);
}

/* 初始化掩码：字母显示为 '_'，空格保持空格 */
void init_mask(const char *answer, char *mask) {
    int n = (int)strlen(answer);
    for (int i = 0; i < n; ++i) mask[i] = isspace((unsigned char)answer[i]) ? ' ' : '_';
    mask[n] = '\0';
}

/* 揭示字母，返回揭示到的数量 */
int reveal_letter(const char *answer, char *mask, char letter) {
    int cnt = 0;
    letter = (char)tolower((unsigned char)letter);
    for (int i = 0; answer[i]; ++i) {
        if (tolower((unsigned char)answer[i]) == letter && mask[i] == '_') {
            mask[i] = answer[i];
            cnt++;
        }
    }
    return cnt;
}

/* 检查是否已全部揭示 */
bool is_solved(const char *mask) {
    for (int i = 0; mask[i]; ++i) if (mask[i] == '_') return false;
    return true;
}

/* 简单判断两个字符串忽略大小写是否相等 */
bool equals_ignore_case(const char *a, const char *b) {
    int la = (int)strlen(a), lb = (int)strlen(b);
    if (la != lb) return false;
    for (int i = 0; i < la; ++i) if (tolower((unsigned char)a[i]) != tolower((unsigned char)b[i])) return false;
    return true;
}

/* 交互式猜词玩法：用户选择行或列并进行猜测 */
int main(void) {
    int rows = RIDDLE_COUNT;
    int cols = max_length_in_array(riddles, RIDDLE_COUNT);

    /* 构造字符网格，注意为安全起见使用固定大列缓冲 */
    /* 构造并显示字符网格（每行以空格补齐至相同长度） */
    char grid[rows][64];
    for (int i = 0; i < rows; ++i) {
        int len = (int)strlen(riddles[i]);
        for (int j = 0; j < cols; ++j) grid[i][j] = (j < len) ? riddles[i][j] : ' ';
        grid[i][cols] = '\0';
    }
    printf("字符网格：\n");
    for (int i = 0; i < rows; ++i) puts(grid[i]);

    /* 选择模式 */
    char line[256];
    char mode = '\0';
    while (mode != 'r' && mode != 'c') {
        printf("\n请选择模式：按行猜(r) 或 按列猜(c) （输入 r 或 c）：");
        if (!fgets(line, sizeof(line), stdin)) return 0;
        if (line[0] == 'r' || line[0] == 'c') mode = line[0];
    }

    int idx = -1;
    while (idx < 1) {
        printf("请输入要猜的索引（从1开始）：");
        if (!fgets(line, sizeof(line), stdin)) return 0;
        idx = atoi(line);
        if (idx < 1) printf("索引必须 >=1，请重试。\n");
    }

    char answer[64];
    if (mode == 'r') {
        if (idx > rows) { printf("行索引超出范围。\n"); return 0; }
        extract_row(grid, cols, idx-1, answer);
    } else {
        if (idx > cols) { printf("列索引超出范围。\n"); return 0; }
        extract_col(grid, rows, idx-1, answer);
    }

    if (strlen(answer) == 0) { printf("所选行/列为空。\n"); return 0; }

    char mask[64];
    init_mask(answer, mask);

    char wrongs[64] = ""; int wrongs_len = 0;
    int tries = 6;

    printf("\n开始游戏！输入单字母或整词猜测，输入 q 退出。\n");
    while (1) {
        printf("\n答案：%s\n", mask);
        printf("错误字母：%s\n", wrongs_len ? wrongs : "无");
        printf("剩余机会：%d\n", tries);
        printf("你的猜测：");
        if (!fgets(line, sizeof(line), stdin)) break;
        rtrim(line);
        if (strlen(line) == 0) continue;
        if (line[0] == 'q') { printf("退出游戏。\n"); break; }
        
        if (strlen(line) == 1 && isalpha((unsigned char)line[0])) {
            char ch = (char)tolower((unsigned char)line[0]);
            int found = reveal_letter(answer, mask, ch);
            if (found > 0) {
                printf("猜对 %d 个位置！\n", found);
                if (is_solved(mask)) { printf("恭喜！你猜出了答案：%s\n", answer); break; }
            } else {
                printf("没有该字母。\n");
                if (wrongs_len < (int)sizeof(wrongs)-2) { wrongs[wrongs_len++] = ch; wrongs[wrongs_len] = '\0'; }
                tries--;
                if (tries <= 0) { printf("机会用尽，答案是：%s\n", answer); break; }
            }
        } else {
            /* 整词猜测 */
            printf("你猜测的整词是：%s\n", line);
            printf("正确答案是：%s\n", answer);

            if (equals_ignore_case(line, answer)) { printf("恭喜！你猜出了答案：%s\n", answer); break; }
            else {
                printf("整词猜测错误。\n");
                tries--;
                if (tries <= 0) { printf("机会用尽，答案是：%s\n", answer); break; }
            }
        }
    }

    return 0;
}
