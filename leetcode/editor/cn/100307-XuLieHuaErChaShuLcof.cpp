//请实现两个函数，分别用来序列化和反序列化二叉树。 
//
// 你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字
//符串反序列化为原始的树结构。 
//
// 提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方
//法解决这个问题。 
//
// 
//
// 示例： 
//
// 
//输入：root = [1,2,3,null,null,4,5]
//输出：[1,2,3,null,null,4,5]
// 
//
// 
//
// 注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-b
//inary-tree/ 
// Related Topics 树 深度优先搜索 广度优先搜索 设计 字符串 二叉树 
// 👍 231 👎 0


#include <sstream>
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *r) {
        if (!r) return "";
        queue<TreeNode *> q;
        ostringstream oss;
        q.push(r);
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            if (!tmp)
                oss << "# ";
            else {
                oss << tmp->val << " ";
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<TreeNode *> nodes;
        string val;
        istringstream iss(data);
        while (iss >> val) {
            if (val == "#")
                nodes.push_back(nullptr);
            else
                nodes.push_back(new TreeNode(stoi(val)));
        }
        int p = 1;
        for (int i = 0; i < nodes.size(); ++i) {
            if (!nodes[i]) continue;
            nodes[i]->left = nodes[p++];
            nodes[i]->right = nodes[p++];
        }
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s << endl;
}