//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。 
//
// 
//
// 示例 1： 
//
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2： 
//
// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
//
// 限制： 
//
// 
// 0 <= matrix.length <= 100 
// 0 <= matrix[i].length <= 100 
// 
//
// 注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/ 
// Related Topics 数组 矩阵 模拟 
// 👍 292 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty()) return {};
        int l = 0, r = matrix[0].size() - 1;
        int t = 0, b = matrix.size() - 1;
        vector<int> ans;
        while (1) {
            //left->right
            for (int i = l; i <= r; ++i) ans.push_back(matrix[t][i]);
            if (++t > b) break;

            //top->bottom
            for (int i = t; i <= b; ++i) ans.push_back(matrix[i][r]);
            if (--r < l) break;

            //right->left
            for (int i = r; i >= l; --i) ans.push_back(matrix[b][i]);
            if (--b < t) break;

            //bottom->top
            for (int i = b; i >= t; --i) ans.push_back(matrix[i][l]);
            if (++l > r) break;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s << endl;
}