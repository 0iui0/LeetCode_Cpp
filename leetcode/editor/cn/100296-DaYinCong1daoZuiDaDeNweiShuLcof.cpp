//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。 
//
// 示例 1: 
//
// 输入: n = 1
//输出: [1,2,3,4,5,6,7,8,9]
// 
//
// 
//
// 说明： 
//
// 
// 用返回一个整数列表来代替打印 
// n 为正整数 
// 
// Related Topics 数组 数学 
// 👍 141 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> printNumbers(int n) {
        string s = "";
        s.append(n,'9');
        int num = stoi(s);
        vector<int> list(num);
        for (int i = 0; i < num; ++i) {
            list[i] = i + 1;
        }
        return list;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    for (auto n: s.printNumbers(2)) {
        cout << n << endl;
    }
}