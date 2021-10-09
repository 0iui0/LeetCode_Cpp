//数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，
//等等。 
//
// 请写一个函数，求任意第n位对应的数字。 
//
// 
//
// 示例 1： 
//
// 输入：n = 3
//输出：3
// 
//
// 示例 2： 
//
// 输入：n = 11
//输出：0 
//
// 
//
// 限制： 
//
// 
// 0 <= n < 2^31 
// 
//
// 注意：本题与主站 400 题相同：https://leetcode-cn.com/problems/nth-digit/ 
// Related Topics 数学 二分查找 👍 173 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //    seq    digit   start    count
    //  1...9      1       1        9
    // 10...99     2       10       90=2*10*9
    // 100...999   3       100      900=2*100*9
    int findNthDigit(int n) {
        long long start = 1;
        int digit = 1;
        long long count = 9;
        while (n > count) {
            n -= count;
            start *= 10;
            digit++;
            count = digit * start * 9;
        }
        int num = start + (n - 1) / digit;
        string s = to_string(num);
        return s[(n - 1) % digit] - '0';
    };
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.findNthDigit(11) << endl;
}