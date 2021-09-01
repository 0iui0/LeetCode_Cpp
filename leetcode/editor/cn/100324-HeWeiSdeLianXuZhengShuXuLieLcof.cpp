//输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。 
//
// 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。 
//
// 
//
// 示例 1： 
//
// 输入：target = 9
//输出：[[2,3,4],[4,5]]
// 
//
// 示例 2： 
//
// 输入：target = 15
//输出：[[1,2,3,4,5],[4,5,6],[7,8]]
// 
//
// 
//
// 限制： 
//
// 
// 1 <= target <= 10^5 
// 
//
// 
// Related Topics 数学 双指针 枚举 
// 👍 308 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int i = 1, j = 2, s = 3;
        vector<vector<int>> ans;
        vector<int> tmp;
        while (i < j) {
            if (s == target) {
                tmp.clear();
                for (int k = i; k <= j; ++k) tmp.push_back(k);
                ans.push_back(tmp);
            }
            if (s >= target) {
                //hit:
                s = s - i;
                i++;
            }
            if (s < target) {
                //hit:
                j++;
                s = s + j;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s << endl;
}