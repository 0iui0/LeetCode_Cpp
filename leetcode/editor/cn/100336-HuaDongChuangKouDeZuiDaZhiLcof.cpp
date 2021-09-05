//给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。 
//
// 示例: 
//
// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
//输出: [3,3,5,5,6,7] 
//解释: 
//
//  滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7 
//
// 
//
// 提示： 
//
// 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。 
//
// 注意：本题与主站 239 题相同：https://leetcode-cn.com/problems/sliding-window-maximum/ 
// Related Topics 队列 滑动窗口 单调队列 堆（优先队列） 
// 👍 317 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if (nums.size() < k || k <= 0) return {};
        deque<int> maxIndex;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k && !maxIndex.empty()) ans.push_back(nums[maxIndex.front()]);
            while (!maxIndex.empty() && nums[i] > nums[maxIndex.back()]) maxIndex.pop_back();
            while (!maxIndex.empty() && maxIndex.front() <= i - k) maxIndex.pop_front();
            maxIndex.push_back(i);
        }
        ans.push_back(nums[maxIndex.front()]);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s << endl;
}