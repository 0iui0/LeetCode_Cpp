//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。 
//
// 
//
// 例如: 
//给定二叉树: [3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回其层次遍历结果： 
//
// [
//  [3],
//  [20,9],
//  [15,7]
//]
// 
//
// 
//
// 提示： 
//
// 
// 节点总数 <= 1000 
// 
// Related Topics 树 广度优先搜索 二叉树 
// 👍 121 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        dfs(0, root);
        stack<int> tmpS;
        vector<int> tmpV;
        for (int i = 1; i < ans.size(); i += 2) {
            tmpV.clear();
            for (int j = ans[i].size() - 1; j >= 0; --j) {
                tmpV.push_back(ans[i][j]);
            }
            ans[i] = tmpV;
        }
        return ans;
    }

private:
    void dfs(int depth, TreeNode *root) {
        if (!root) return;
        if (depth == ans.size()) ans.push_back(vector<int>{});
        ans[depth].push_back(root->val);
        dfs(depth + 1, root->left), dfs(depth + 1, root->right);
    }

private:
    vector<vector<int>> ans;
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    TreeNode *r = new TreeNode(0);
    TreeNode *l0 = new TreeNode(1);
    TreeNode *r0 = new TreeNode(2);
    TreeNode *r1 = new TreeNode(3);
    r->left = l0;
    r->right = r0;
    r0->right = r1;
    print_tree(r);
    s.levelOrder(r);
//    cout cout<< s << endl;
}