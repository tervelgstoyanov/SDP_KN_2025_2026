### Data structures and Programming - Seminar
# Week 9 - N-ary trees

## Definition
```cpp
template <class T>
struct Node {
    T value;
    std::vector<Node*> children;

    Node(const T& val = T{}, std::vector<Node*> children = std::vector<Node*>())
        : value(val), children(children) {}
};
```

## Problems
**P1.** Write a function that by pointer to the root of n-ary tree return a list of lists where each list contains the value of the corresponding level in the tree.

**P2.** A n-ary tree is represented like that:
- on the first line in a file is written the label of the root;
- on the second line are written the children of the root split with space;
- on each next line are written the children from the previous line split with spaces and stars between the brotherhoods; if there is "* *" that means that the corresponding node is a leaf.

Read such trees from file and print the sentence of the most right children.

**P3.** Write a function that compares two n-ary trees(with respect to children order, with no respect of children order).

**P4.** Given a parent array construct n-ary tree.

**P5.** Serialize the tree in the format from exercise 2.
