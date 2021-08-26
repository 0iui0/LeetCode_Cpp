//输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。 
//
// 
//
// 示例 1： 
//
// 输入：arr = [3,2,1], k = 2
//输出：[1,2] 或者 [2,1]
// 
//
// 示例 2： 
//
// 输入：arr = [0,1,2,1], k = 1
//输出：[0] 
//
// 
//
// 限制： 
//
// 
// 0 <= k <= arr.length <= 10000 
// 0 <= arr[i] <= 10000 
// 
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 
// 👍 288 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        quick_sort(arr, 0, arr.size()-1);
        vector<int> ans;
        ans.assign(arr.begin(), arr.begin() + k);
        return ans;
    }

private:
    void quick_sort(vector<int> &arr, int l, int r) {
        if (l >= r) return;
        int i = l - 1, j = r + 1, x = arr[(l + r) >> 1];
        while (i < j) {
            do i++; while (arr[i] < x);
            do j--; while (arr[j] > x);
            if (i < j) swap(arr[i], arr[j]);
        }
        quick_sort(arr, l, j), quick_sort(arr, j + 1, r);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> arr{2, 3, 1, 4, 7, 4, 8, 3, 6, 9};
    auto ans = s.getLeastNumbers(arr, 6);
    for (int n:ans) {
        cout << n << endl;
    }
}