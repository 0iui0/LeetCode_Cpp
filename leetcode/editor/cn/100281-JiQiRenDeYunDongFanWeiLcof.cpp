//地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一
//格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但
//它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？ 
//
// 
//
// 示例 1： 
//
// 输入：m = 2, n = 3, k = 1
//输出：3
// 
//
// 示例 2： 
//
// 输入：m = 3, n = 1, k = 0
//输出：1
// 
//
// 提示： 
//
// 
// 1 <= n,m <= 100 
// 0 <= k <= 20 
// 
// Related Topics 深度优先搜索 广度优先搜索 动态规划 
// 👍 329 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<bool> vis(m * n, false);
        queue<int> Q;
        int cnt = 0;
        Q.push(0);
        vis[0] = true;
        while (!Q.empty()) {
            int start = Q.front();
            Q.pop();
            cnt++;
            int right = start + 1;
            int down = start + n;
            if (start % n == (n - 1)) {
                right = -1;
            }
            int dirs[2] = {right, down};
            for (auto di:dirs) {
                if (di >= 0 && di < m * n && !vis[di] && sumDigtial(di / n) + sumDigtial(di % n) <= k) {
                    vis[di] = true;
                    Q.push(di);
                }
            }
        }
        return cnt;
    }


private:
    int sumDigtial(int a) {
        int sum = a % 10;
        int tmp = a / 10;
        while (tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto res = s.movingCount(14, 14, 5);
    cout << res << endl;
}