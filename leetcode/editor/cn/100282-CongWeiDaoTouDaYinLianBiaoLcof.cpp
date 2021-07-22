//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。 
//
// 
//
// 示例 1： 
//
// 输入：head = [1,3,2]
//输出：[2,3,1] 
//
// 
//
// 限制： 
//
// 0 <= 链表长度 <= 10000 
// Related Topics 栈 递归 链表 双指针 
// 👍 167 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode *head) {
        stack<int> stack1;
        vector<int> linkedList;
        while (head != nullptr) {
            stack1.push(head->val);
            head = head->next;
        }
        while (!stack1.empty()) {
            linkedList.push_back(stack1.top());
            stack1.pop();
        }
        return linkedList;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    ListNode l3 = ListNode();
    l3.val = 3;
    ListNode l2 = ListNode();
    l2.val = 2;
    ListNode l4 = ListNode();
    l4.val = 4;

    l4.next = &l3;
    l3.next = &l2;
    auto res = s.reversePrint(&l4);
    for (auto val:res) {
        cout << val << endl;
    }
}