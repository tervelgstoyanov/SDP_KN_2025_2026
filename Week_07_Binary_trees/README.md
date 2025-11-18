### Data structures and Programming - Seminar
# Week 7 - Introduction to Trees. Binary trees

## Tree
**Tree** is a basic data structure. The main idea behind it is to easily manage a tree-like sequence of nodes in the memory - each node contains some value and pointers to its children. The simplest version of a tree is the binary tree - each node has at most two children. The idea of a **node** is crucial so here is some definition in C++:
```cpp
template <class T>
struct BinTreeNode {
    T value;
    BinTreeNode *left, *right;

    BinTreeNode(const T& val = T{}, BinTreeNode* left = nullptr, BinTreeNode* right = nullptr);
};
```
There are more exotic types of trees, e.g. *n-ary tree* and *(balanced) ordered tree*(next week).

## Traversals
- DFS based - **inorder**, **preorder**, **postorder**;
- BFS based - traverse the tree per levels.

## Problems
**P1.** Write a function to deallocate a binary tree.

**P2.** Write a function that finds the height of a binary tree.

**P3.** Write a function that counts the number of nodes in a binary tree.

**P4.** Write a function that returns all elements from a binary tree for which a given predicate is `true`.

**P5.** Write functions that realize the different traverses of a binary tree:
- inorder;
- preorder;
- postorder;
- per levels.