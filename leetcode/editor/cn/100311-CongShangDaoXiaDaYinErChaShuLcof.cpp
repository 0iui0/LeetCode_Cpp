//从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。 
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
// 返回： 
//
// [3,9,20,15,7]
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
// 👍 112 👎 0


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
    vector<int> levelOrder(TreeNode *root) {
        vector<int> v;
        if (root == NULL) return v;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            v.push_back(tmp->val);
            q.pop();
            if (tmp->left!=NULL)
                q.push(tmp->left);
            if (tmp->right!=NULL)
                q.push(tmp->right);
        }
        return v;
    }
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
//    cout << s.levelOrder(r) << endl;
}