//请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。 
//
// 
//
// 示例 1: 
//
// 输入: "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 
//
// 提示： 
//
// 
// s.length <= 40000 
// 
//
// 注意：本题与主站 3 题相同：https://leetcode-cn.com/problems/longest-substring-without-rep
//eating-characters/ 
// Related Topics 哈希表 字符串 滑动窗口 
// 👍 265 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len < 2) return len;
        vector<int> dp(len);
        dp[0] = 1;
        dp[1] = 1;
        int subStart = 0;
        int subEnd = 0;
        int max = 1;
        string subStr = s.substr(subStart, subEnd - subStart + 1);
        for (int i = 1; i < len; ++i) {
            dp[i] = dp[i - 1];
            string ch = s.substr(i, 1);
            int n = subStr.find(ch);
            if (n >= 0 && n < len) {
                subStart = i - subStr.length() + n + 1;
            }
            subEnd = i;
            subStr = s.substr(subStart, subEnd - subStart + 1);
            if (subStr.length() > max) {
                max = subStr.length();
                dp[i] = max;
            }
        }
        return dp[len - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("bbbb") << endl;
}