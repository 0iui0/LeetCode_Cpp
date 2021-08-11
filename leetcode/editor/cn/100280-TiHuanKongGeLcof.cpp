//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。 
//
// 
//
// 示例 1： 
//
// 输入：s = "We are happy."
//输出："We%20are%20happy." 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 10000 
// Related Topics 字符串 
// 👍 143 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string replaceSpace(string s) {
        char oldVal = ' ';
        string newVal = "%20";
        int pos = 0;
        while (pos < s.length()) {
            if (s[pos] == oldVal) {
                s.replace(pos, 1, newVal);
                pos += newVal.length();
            } else pos++;
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    string str="We are happy";
    auto res = s.replaceSpace(str);
    cout << res << endl;
}