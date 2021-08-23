//在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直
//到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？ 
//
// 
//
// 示例 1: 
//
// 输入: 
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//输出: 12
//解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物 
//
// 
//
// 提示： 
//
// 
// 0 < grid.length <= 200 
// 0 < grid[0].length <= 200 
// 
// Related Topics 数组 动态规划 矩阵 
// 👍 167 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxValue(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(r + 1, vector<int>(c + 1, 0));
        for (int i = 1; i < r + 1; ++i) {
            for (int j = 1; j < c + 1; ++j) {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + grid[i-1][j-1];
            }
        }
        return dp[r][c];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    cout << s.maxValue(grid) << endl;
}