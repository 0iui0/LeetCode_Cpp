//请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配
//是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。 
//
// 示例 1: 
//
// 输入:
//s = "aa"
//p = "a"
//输出: false
//解释: "a" 无法匹配 "aa" 整个字符串。
// 
//
// 示例 2: 
//
// 输入:
//s = "aa"
//p = "a*"
//输出: true
//解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
// 
//
// 示例 3: 
//
// 输入:
//s = "ab"
//p = ".*"
//输出: true
//解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
// 
//
// 示例 4: 
//
// 输入:
//s = "aab"
//p = "c*a*b"
//输出: true
//解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
// 
//
// 示例 5: 
//
// 输入:
//s = "mississippi"
//p = "mis*is*p*."
//输出: false 
//
// 
// s 可能为空，且只包含从 a-z 的小写字母。 
// p 可能为空，且只包含从 a-z 的小写字母以及字符 . 和 *，无连续的 '*'。 
// 
//
// 注意：本题与主站 10 题相同：https://leetcode-cn.com/problems/regular-expression-matching/
// 
// Related Topics 递归 字符串 动态规划 
// 👍 266 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length() + 1, n = p.length() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = 1;
        for (int i = 2; i < n; i += 2) {
            dp[0][i] = dp[0][i - 2] && p[i - 1] == '*';
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (p[j - 1] == '*') {
                    if (dp[i][j - 2]) dp[i][j] = true;
                    else if (dp[i - 1][j] && p[j - 2] == '.') dp[i][j] = true;
                    else if (dp[i - 1][j] && p[j - 2] == s[i - 1]) dp[i][j] = true;
                } else {
                    if (dp[i - 1][j - 1] && p[j - 1] == s[i - 1]) dp[i][j] = true;
                    else if (dp[i - 1][j - 1] && p[j - 1] == '.') dp[i][j] = true;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.isMatch("aaa", "a*") << endl;
}