//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数
//值排序之后中间两个数的平均值。 
//
// 例如， 
//
// [2,3,4] 的中位数是 3 
//
// [2,3] 的中位数是 (2 + 3) / 2 = 2.5 
//
// 设计一个支持以下两种操作的数据结构： 
//
// 
// void addNum(int num) - 从数据流中添加一个整数到数据结构中。 
// double findMedian() - 返回目前所有元素的中位数。 
// 
//
// 示例 1： 
//
// 输入：
//["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
//[[],[1],[2],[],[3],[]]
//输出：[null,null,null,1.50000,null,2.00000]
// 
//
// 示例 2： 
//
// 输入：
//["MedianFinder","addNum","findMedian","addNum","findMedian"]
//[[],[2],[],[3],[]]
//输出：[null,null,2.00000,null,2.50000] 
//
// 
//
// 限制： 
//
// 
// 最多会对 addNum、findMedian 进行 50000 次调用。 
// 
//
// 注意：本题与主站 295 题相同：https://leetcode-cn.com/problems/find-median-from-data-strea
//m/ 
// Related Topics 设计 双指针 数据流 排序 堆（优先队列） 
// 👍 171 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class MedianFinder {
private:
    //大顶堆，存左半部分，堆顶是最大元素
    priority_queue<int, vector<int>, less<int>> halfLeftMaxHeap;
    //小顶堆，存右半部分，堆顶是最小元素
    priority_queue<int, vector<int>, greater<int>> halfRightMinHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (halfLeftMaxHeap.size() == halfRightMinHeap.size()) {
            halfRightMinHeap.push(num);
            int top = halfRightMinHeap.top();
            halfRightMinHeap.pop();
            halfLeftMaxHeap.push(top);
        } else {
            halfLeftMaxHeap.push(num);
            int top = halfLeftMaxHeap.top();
            halfLeftMaxHeap.pop();
            halfRightMinHeap.push(top);
        }
    }

    double findMedian() {
        if (halfLeftMaxHeap.size() != halfRightMinHeap.size())
            return halfLeftMaxHeap.top() * 1.0;
        else
            return (halfLeftMaxHeap.top() + halfRightMinHeap.top()) * 1.0 / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    MedianFinder mf;
    mf.addNum(2);
    mf.addNum(8);
    mf.addNum(5);
    cout << mf.findMedian() << endl;
}