//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。 
//
// 数值（按顺序）可以分成以下几个部分： 
//
// 
// 若干空格 
// 一个 小数 或者 整数 
// （可选）一个 'e' 或 'E' ，后面跟着一个 整数 
// 若干空格 
// 
//
// 小数（按顺序）可以分成以下几个部分： 
//
// 
// （可选）一个符号字符（'+' 或 '-'） 
// 下述格式之一：
// 
// 至少一位数字，后面跟着一个点 '.' 
// 至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字 
// 一个点 '.' ，后面跟着至少一位数字 
// 
// 
// 
//
// 整数（按顺序）可以分成以下几个部分： 
//
// 
// （可选）一个符号字符（'+' 或 '-'） 
// 至少一位数字 
// 
//
// 部分数值列举如下： 
//
// 
// ["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"] 
// 
//
// 部分非数值列举如下： 
//
// 
// ["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"] 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "0"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：s = "e"
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：s = "."
//输出：false 
//
// 示例 4： 
//
// 
//输入：s = "    .1  "
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 20 
// s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，空格 ' ' 或者点 '.' 。 
// 
// Related Topics 字符串 
// 👍 234 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isNumber(string s) {
        unordered_map<char, int> transTab[9];
        transTab[0][' '] = 0, transTab[0]['s'] = 1, transTab[0]['d'] = 2, transTab[0]['.'] = 4;
        transTab[1]['d'] = 2, transTab[1]['.'] = 4;
        transTab[2]['d'] = 2, transTab[2]['.'] = 3, transTab[2]['e'] = 5, transTab[2][' '] = 8;
        transTab[3]['d'] = 3, transTab[3]['e'] = 5, transTab[3][' '] = 8;
        transTab[4]['d'] = 3;
        transTab[5]['s'] = 6, transTab[5]['d'] = 7;
        transTab[6]['d'] = 7;
        transTab[7]['d'] = 7, transTab[7][' '] = 8;
        transTab[8][' '] = 8;
        int p = 0;
        char t;
        for (char c:s) {
            if (c >= '0' && c <= '9') t = 'd';
            else if (c == '+' || c == '-') t = 's';
            else if (c == 'e' || c == 'E') t = 'e';
            else t = c;
            if (transTab[p].find(t) == transTab[p].end()) return false;
            p = transTab[p][t];
        }
        return p == 2 || p == 3 || p == 7 || p == 8;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.isNumber(" 0.23e06 ") << endl;
}