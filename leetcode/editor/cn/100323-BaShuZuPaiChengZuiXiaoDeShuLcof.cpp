//输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。 
//
// 
//
// 示例 1: 
//
// 输入: [10,2]
//输出: "102" 
//
// 示例 2: 
//
// 输入: [3,30,34,5,9]
//输出: "3033459" 
//
// 
//
// 提示: 
//
// 
// 0 < nums.length <= 100 
// 
//
// 说明: 
//
// 
// 输出结果可能非常大，所以你需要返回一个字符串而不是整数 
// 拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0 
// 
// Related Topics 贪心 字符串 排序 
// 👍 265 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minNumber(vector<int> &nums) {
        vector<string> strs;
        for (int i:nums) {
            strs.push_back(to_string(i));
        }
        sort(strs.begin(), strs.end(), [](string &x, string &y) { return x + y < y + x; });
        string str = "";
        for (auto s:strs) {
            str.append(s);
        }
        return str;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> arr{2, 30, 1, 70, 97, 4, 8, 0, 6, 9};
    cout << s.minNumber(arr) << endl;
}