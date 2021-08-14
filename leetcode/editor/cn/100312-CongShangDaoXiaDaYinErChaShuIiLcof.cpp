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
        if (root == NULL) return v;
        queue<TreeNode *> q;
        q.push(root);
        int nextLv = 0, toBePrint = 1;
        vector<int> tmpV;
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            tmpV.push_back(tmp->val);
            if (tmp->left != NULL) {
                q.push(tmp->left);
                ++nextLv;
            }
            if (tmp->right != NULL) {
                q.push(tmp->right);
                ++nextLv;
            }
            q.pop();
            --toBePrint;
            if (toBePrint == 0) {
                v.push_back(tmpV);
                tmpV.clear();
                toBePrint = nextLv;
                nextLv = 0;
            }
        }
        return v;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s << endl;
}