/**
 * 解决思路
用递归函数处理文件：
1. 打开当前文件
2. 逐行读取
3. 如果这一行是 include 语句，就递归处理被包含的文件
4. 否则把这行直接输出
5. 用一个“当前包含链”记录文件名，避免重复包含同一个文件
 */
#include <stdio.h>
#include <string.h>

#define MAX_DEPTH 20
#define MAX_NAME 100

static char stack[MAX_DEPTH][MAX_NAME];
static int depth = 0;

static int in_stack(const char *name)
{
    for (int i = 0; i < depth; ++i) {
        if (strcmp(stack[i], name) == 0)
            return 1;
    }
    return 0;
}

static void push_stack(const char *name)
{
    if (depth < MAX_DEPTH) {
        strcpy(stack[depth], name);
        depth++;
    }
}

static void pop_stack(void)
{
    if (depth > 0)
        depth--;
}

static void process_file(const char *name)
{
    FILE *fp;
    char line[512];
    char include_name[MAX_NAME];

    fp = fopen(name, "r");
    if (fp == NULL) {
        fprintf(stderr, "cannot open %s\n", name);
        return;
    }

    if (in_stack(name)) {
        fprintf(stderr, "skip recursive include: %s\n", name);
        fclose(fp);
        return;
    }

    push_stack(name);

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "# include %99s", include_name) == 1 ||
            sscanf(line, "#include %99s", include_name) == 1) {
            process_file(include_name);
        } else {
            fputs(line, stdout);
        }
    }

    pop_stack();
    fclose(fp);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        return 1;
    }

    process_file(argv[1]);
    return 0;
}