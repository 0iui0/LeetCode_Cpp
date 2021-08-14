//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。 
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
//  [9,20],
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
//
// 注意：本题与主站 102 题相同：https://leetcode-cn.com/problems/binary-tree-level-order-tra
//versal/ 
// Related Topics 树 广度优先搜索 二叉树 
// 👍 126 👎 0


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
        vector<vector<int>> v;
        if (!root) return v;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmpV;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *tmp = q.front();
                q.pop();
                tmpV.push_back(tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            v.push_back(tmpV);
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
//    cout << s << endl;
}