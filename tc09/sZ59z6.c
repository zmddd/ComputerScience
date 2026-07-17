// 力扣刷题模板:只要把 numColor 这个函数贴进去就能 AC
// (TreeNode 是力扣自带的,不用自己写)

// ---- 递归函数:深度优先遍历整棵树 ----
void dfs(struct TreeNode* root, bool* v, int* ans) {
    // 第 1 行:递归出口
    // 如果当前节点是空(NULL),说明走到底了,直接返回
    // !root 等价于 root == NULL,因为 NULL 在条件里就是"假"
    if (!root) return;

    // 第 2~3 行:去重 + 计数
    // v[root->val] 表示"颜色 root->val 是否已经出现过"
    // root->val 等价于 (*root).val,因为 root 是指针,要先解引用再取成员
    // !v[root->val] 表示"还没出现过"
    if (!v[root->val]) {
        v[root->val] = true;  // 标记这个颜色"已出现",下次再见到就跳过
        (*ans)++;             // 答案 +1
        // *ans 才是 ans 指针指向的那个整数,直接写 ans++ 改的是指针本身(错的)
    }

    // 第 4~5 行:继续往下走
    // 先递归处理左子树
    dfs(root->left,  v, ans);
    // 再递归处理右子树
    dfs(root->right, v, ans);
    // 这就是"前序遍历":根 → 左 → 右
}

// ---- 主函数:LeetCode 的入口 ----
int numColor(struct TreeNode* root) {
    // 声明一个大小为 1001 的布尔数组,初值全是 false
    // 题目说颜色值 1 <= val <= 1000,1001 足够装下所有可能的颜色
    // = {false} 这种写法会把数组所有元素都初始化为 false
    bool v[1001] = {false};

    // ans 用来计数:出现了多少种不同的颜色
    int ans = 0;

    // 启动递归
    // &ans 表示"取 ans 的地址",函数里通过 *ans 才能修改它
    dfs(root, v, &ans);

    // 把最终结果返回给 LeetCode
    return ans;
}