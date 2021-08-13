//在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。 
//
// 示例: 
//
// s = "abaccdeff"
//返回 "b"
//
//s = "" 
//返回 " "
// 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 50000 
// Related Topics 队列 哈希表 字符串 计数 
// 👍 124 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    char firstUniqChar(string s) {
        if (s.empty()) return ' ';
        map<char, int> charMap;
        for (int i = 0; i < s.length(); ++i) {
            charMap[s[i]]++;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (charMap[s[i]] == 1) return s[i];
        }
        return ' ';
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.firstUniqChar("baa") << endl;
}