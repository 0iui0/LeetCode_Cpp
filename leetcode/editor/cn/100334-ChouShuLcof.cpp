//我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。 
//
// 
//
// 示例: 
//
// 输入: n = 10
//输出: 12
//解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。 
//
// 说明: 
//
// 
// 1 是丑数。 
// n 不超过1690。 
// 
//
// 注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/ 
// Related Topics 哈希表 数学 动态规划 堆（优先队列） 
// 👍 209 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 0, i3 = 0, i5 = 0;
        int dp[n];
        dp[0] = 1;
        for (int j = 1; j < n; ++j) {
            int n2 = dp[i2] * 2, n3 = dp[i3] * 3, n5 = dp[i5] * 5;
            dp[j] = min(min(n2, n3), n5);
            if (dp[j] == n2) i2++;
            if (dp[j] == n3) i3++;
            if (dp[j] == n5) i5++;
        }
        return dp[n - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s << endl;
}