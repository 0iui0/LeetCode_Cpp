//把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。 
//
// 
//
// 你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。 
//
// 
//
// 示例 1: 
//
// 输入: 1
//输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
// 
//
// 示例 2: 
//
// 输入: 2
//输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0
//.05556,0.02778] 
//
// 
//
// 限制： 
//
// 1 <= n <= 11 
// Related Topics 数学 动态规划 概率与统计 👍 294 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<double> dicesProbability(int N) {
        vector<vector<int>> dp(N + 1, vector<int>(6 * N + 1, 0));
        vector<double> ans(6 * N - N + 1);
        //初始化
        for (int i = 1; i <= 6; ++i) {
            dp[1][i] = 1;
        }
        for (int n = 2; n < dp.size(); ++n) {
            for (int s = n; s < dp[0].size(); ++s) {
                for (int k = 1; k <= 6; ++k) {
                    if (s - k > 0) {
                        dp[n][s] += dp[n - 1][s - k];
                    }
                }
            }
        }
        double demo = pow(6.0, N);
        for (int s = N; s <= 6 * N; ++s) {
            ans[s - N] = dp[N][s] / demo;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    for (auto prob: s.dicesProbability(3)) {
        cout << prob << endl;
    }
}