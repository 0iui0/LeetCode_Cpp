//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2
//] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。 
//
// 示例 1： 
//
// 输入：[3,4,5,1,2]
//输出：1
// 
//
// 示例 2： 
//
// 输入：[2,2,2,0,1]
//输出：0
// 
//
// 注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sor
//ted-array-ii/ 
// Related Topics 数组 二分查找 
// 👍 370 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minArray(vector<int> &numbers) {
        int low = 0;
        int high = numbers.size() - 1;
        if(numbers[low]<numbers[high])
            return numbers[low];
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (numbers[pivot] > numbers[high]) {
                low = pivot + 1;
            } else if (numbers[pivot] < numbers[high]) {
                high = pivot;
            } else {
                high--;
            }
        }
        return numbers[low];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data{1, 0, 1, 1, 1, 1};
    auto res = s.minArray(data);
    cout << res << endl;
}