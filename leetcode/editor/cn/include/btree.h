/**
 * 
 * Copyright (c) 2019 NUAA Jiang Yang
 * 
 * @file
 * @author   Jiang Yang (pokerpoke@qq.com)
 * @date     2018-09
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-08-13
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#ifndef _BTREE_H_
#define _BTREE_H_

#include <vector>
#include <iostream>
#include <initializer_list>
#include <queue>
#include <list>

namespace LeetCode
{

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
};

void print_tree(TreeNode *root);
bool is_same_tree(TreeNode *root1, TreeNode *root2);

class Tree
{
public:
    TreeNode *root;

private:
    std::queue<int> q;

public:
    Tree(std::initializer_list<int> il);
    ~Tree();
    void print();
    bool operator==(const Tree &t2) const;

private:
    TreeNode *deserialize(std::queue<int> &in);
};
    class Node {
    public:
        int val;
        Node *left;
        Node *right;

        Node() {}

        Node(int _val) {
            val = _val;
            left = NULL;
            right = NULL;
        }

        Node(int _val, Node *_left, Node *_right) {
            val = _val;
            left = _left;
            right = _right;
        }
    };
} // namespace LeetCode

#endif //!_BTREE_H_