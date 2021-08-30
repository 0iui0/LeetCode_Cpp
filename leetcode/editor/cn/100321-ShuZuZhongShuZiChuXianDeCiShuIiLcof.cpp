//在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [3,4,3,3]
//输出：4
// 
//
// 示例 2： 
//
// 输入：nums = [9,1,7,9,7,9,7]
//输出：1 
//
// 
//
// 限制： 
//
// 
// 1 <= nums.length <= 10000 
// 1 <= nums[i] < 2^31 
// 
//
// 
// Related Topics 位运算 数组 
// 👍 223 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        vector<int> bitCnt(32, 0);
        for (int n:nums) {
            unsigned int bitMask = 1;
            for (int j = 31; j >= 0; --j) {
                unsigned int bit = n & bitMask;
                if (bit != 0) bitCnt[j] = bitCnt[j] + 1;
                bitMask = bitMask << 1;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            res = res << 1;
            res = res + bitCnt[i] % 3;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s << endl;
}