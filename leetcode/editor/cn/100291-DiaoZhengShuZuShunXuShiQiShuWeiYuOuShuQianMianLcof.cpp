//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。 
//
// 
//
// 示例： 
//
// 
//输入：nums = [1,2,3,4]
//输出：[1,3,2,4] 
//注：[3,1,2,4] 也是正确的答案之一。 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 50000 
// 1 <= nums[i] <= 10000 
// 
// Related Topics 数组 双指针 排序 
// 👍 150 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int> &nums) {
        int low = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] & 0x1) {
                swap(nums[low], nums[fast]);
                low++;
            }
            fast++;
        }
        return nums;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data{1, 2, 3, 4, 5};
    s.exchange(data);
}