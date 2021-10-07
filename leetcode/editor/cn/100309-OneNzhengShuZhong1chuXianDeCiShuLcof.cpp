//输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。 
//
// 例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 12
//输出：5
// 
//
// 示例 2： 
//
// 
//输入：n = 13
//输出：6 
//
// 
//
// 限制： 
//
// 
// 1 <= n < 2^31 
// 
//
// 注意：本题与主站 233 题相同：https://leetcode-cn.com/problems/number-of-digit-one/ 
// Related Topics 递归 数学 动态规划 👍 237 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countDigitOne(int n) {
        int k = 1;
        long digit = 1;
        int res = 0, high = n / 10, low = 0, cur = n % 10;
        while (high || (cur && k)) {
            if (cur < k)
                res += high * digit;
            else if(cur == k)
                res += (high - (k == 0)) * digit + low + 1;
            else
                res += (high + (k != 0)) * digit;
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res + (k == 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.countDigitOne(1410065408) << endl;
}