//运用你所掌握的数据结构，设计和实现一个 LRU (最近最少使用) 缓存机制 。 
//
// 
// 
// 实现 LRUCache 类： 
//
// 
// LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上
//限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。 
// 
//
// 
// 
// 
//
// 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？ 
//
// 
//
// 示例： 
//
// 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 10000 
// 0 <= value <= 10⁵ 
// 最多调用 2 * 10⁵ 次 get 和 put 
// 
// Related Topics 设计 哈希表 链表 双向链表 👍 1676 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class DLinkedNode {
public:
    DLinkedNode *pre;
    DLinkedNode *next;
    int key, value;

    DLinkedNode(int _key, int _value) : pre(nullptr), next(nullptr), key(_key), value(_value) {}

    DLinkedNode() : pre(nullptr), next(nullptr), key(0), value(0) {}
};

class LRUCache {
    unordered_map<int, DLinkedNode *> cache;
    int cap;
    int size;
    DLinkedNode *head;
    DLinkedNode *tail;
public:
    LRUCache(int capacity) : cap(capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->pre = head;
    }

    void addToHead(DLinkedNode *node) {
        head->next->pre = node;
        node->pre = head;
        node->next = head->next;
        head->next = node;
    }

    void removeNode(DLinkedNode *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    int get(int key) {
        //0。不存在，返回-1
        if (!cache.count(key)) return -1;
        //1。存在，删掉，插入头部，返回value
        DLinkedNode *node = cache[key];
        removeNode(node);
        addToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        // 0.key存在，删掉原来的，更新value，再插入头部
        // 1.key不存在,size++，size<=cap,直接插入头部;size>cap,删掉尾巴，插入头部
        if (cache.count(key)) {
            DLinkedNode *oldNode = cache[key];
            removeNode(oldNode);
            addToHead(oldNode);
            cache[key]->value=value;
        } else {
            DLinkedNode *node=new DLinkedNode(key,value);
            addToHead(node);
            cache[key]=node;
            size++;
            if (size > cap)  {
                DLinkedNode *tmp = tail->pre;
                removeNode(tmp);
                cache.erase(tmp->key);
                delete tmp;
                size--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    LRUCache *obj = new LRUCache(3);
    int param_2 = obj->get(2);
    cout << param_2 << endl;
    obj->put(1, 2);
    int param_1 = obj->get(1);
    cout << param_1 << endl;
}