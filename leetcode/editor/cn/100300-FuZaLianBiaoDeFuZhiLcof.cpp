//请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指
//向链表中的任意节点或者 null。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
// 
//
// 示例 2： 
//
// 
//
// 输入：head = [[1,1],[2,1]]
//输出：[[1,1],[2,1]]
// 
//
// 示例 3： 
//
// 
//
// 输入：head = [[3,null],[3,0],[3,null]]
//输出：[[3,null],[3,0],[3,null]]
// 
//
// 示例 4： 
//
// 输入：head = []
//输出：[]
//解释：给定的链表为空（空指针），因此返回 null。
// 
//
// 
//
// 提示： 
//
// 
// -10000 <= Node.val <= 10000 
// Node.random 为空（null）或指向链表中的节点。 
// 节点数目不超过 1000 。 
// 
//
// 
//
// 注意：本题与主站 138 题相同：https://leetcode-cn.com/problems/copy-list-with-random-point
//er/ 
//
// 
// Related Topics 哈希表 链表 
// 👍 249 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// Definition for a Node.
//class Node {
//public:
//    int val;
//    Node* next;
//    Node* random;
//
//    Node(int _val) {
//        val = _val;
//        next = NULL;
//        random = NULL;
//    }
//};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* cur=head;
        while (cur){
            Node* tmp=new Node(cur->val);
            tmp->next=cur->next;
            cur->next=tmp;
            cur=cur->next->next;
        }
        cur=head;
        while (cur){
            if(cur->random){
                cur->next->random=cur->random->next;
            }
            cur=cur->next->next;
        }
        Node* pre=head;
        cur=head->next;
        Node* res=head->next;
        while (cur->next){
            pre->next=pre->next->next;
            cur->next=cur->next->next;
            pre=pre->next->next;
            cur=cur->next->next;
        }
        pre->next= nullptr;
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout<< s <<endl;
}