//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。 
//
// 
//
// 示例 1: 
//
// 输入: [7,5,6,4]
//输出: 5 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 50000 
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 530 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reversePairs(vector<int> &nums) {
        vector<int> temps(nums.size());
        return mergeSort(nums, temps, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int> &nums, vector<int> &temps, int l, int r) {
        // 终止条件
        if (l >= r) return 0;
        // 递归划分
        int m = (l + r) / 2;
        int i = l, j = m + 1;
        int cnt = mergeSort(nums, temps, l, m) + mergeSort(nums, temps, m + 1, r);
        // 合并阶段
        for (int k = l; k <= r; ++k) {
            temps[k] = nums[k];
        }
        for (int k = l; k <= r; ++k) {
            if (i == m + 1) {
                nums[k] = temps[j];
                j++;
            } else if (j == r + 1 || temps[i] <= temps[j]) {
                nums[k] = temps[i];
                i++;
            } else {
                nums[k] = temps[j];
                j++;
                cnt += m + 1 - i;// 统计逆序对
            }
        }
        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> nums{8, 2, 8, 3, 2, 3, 94, 1, 0, 4};
    cout << s.reversePairs(nums) << endl;
}