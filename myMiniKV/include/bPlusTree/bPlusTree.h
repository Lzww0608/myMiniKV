#pragma once

#include <iostream>
#include <stdio.h>
#include <alogrithm>
#include <cassert>
#include <cmath>
#include <vector>
#include <string>

template <typename K, typename V>
class TreeNode {
public:
    //存储key索引
    std::vector<K> keys;
    //tag为0表示叶子结点
    bool tag;
    //叶子结点存储数据，非叶子结点指向下一层节点
    struct {
        std::vector<V> data;
        std::vector<TreeNode<K, V>*> sons;
    }
    //叶子结点指向下一个叶子结点的指针
    TreeNode<K, V>* rLink;
}

template <typename K, typename V>
class BPlusTree {
private:
    //根节点
    TreeNode<K, V>* root;
    //指向叶子结点链表的头结点
    TreeNode<K, V>* linkHead;
    //阶数：一个结点最多有k个key
    int k;

private:
    //二分查找位置
    size_t bSearch(std::vector<K> indexes, K key);

    //往上更新索引
    void up_update(TreeNode<K, V>* p, std::vector<TreeNode<K, V>*> Stack, int i);

    //查找结点
    TreeNode<K, V>* findNode(K key, std::vector<TreeNode<K, V>*>& s);

    //根节点拆分
    void rootDivide(TreeNode<K, V>* parent);

public:
    BPlusTree(int k);

    bool find(K key, V& data);

    bool add(K key, V data);

    bool remove(K key);

    void print(TreeNode<K, V>* root);

    void showTree();
}
//二分查找位置
template <typename K, typename V>
size_t BPlusTree<K, V>::bSearch(std::vector<K> indexes, K key) {
    int l = 0, r = indexes.size() - 1;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (indexes[l] < key) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
//向上更新索引
template <typename K, typename V>
void BPlusTree<K, V>::up_update(TreeNode<K, V>* p, std::vector<TreeNode<K, V>*> Stack, int i) {

} 


template <typename K, typename V>
TreeNode<K, V>* BPlusTree<K, V>::findNode(K key, std::vector<TreeNode<K, V>*>& s) {
    if (root == nullptr || linkHead == nullptr) return nullptr;
    assert(root && linkHead);

    auto p = root;
    //向下遍历直到叶子结点，并记录路径用于后续更新索引
    while (p->tag) {
        s.push_back(p);
        size_t pos = bSearch(p->keys, key);
        //二分查找超界，说明该节点在最后一个子节点的右侧
        if (pos == p->values.sons.size()) {
            pos--;
        }
        p = p->values.sons[pos];
    }
    return p;
}