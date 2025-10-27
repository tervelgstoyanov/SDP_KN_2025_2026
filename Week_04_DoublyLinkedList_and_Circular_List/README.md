### Data structures and Programming - Seminar
# Week 4 - Doubly Linked List and Circular List

## Doubly Linked List 
**Doubly linked list** is the same as the SLL with the exception that each node contains a pointer also to the previous node in the list.
```cpp
template <class T>
struct Node {
    T value;
    Node *prev, *next;

    Node(const T& val = T{}, Node *prev = nullptr, Node *next = nullptr);
};
```
There are more exotic types of linked lists, e.g. *doubly linked lists* and *circular linked lists*(next week).

## Problems
**P1.** Check if there is a cycle in a singly linked list by a pointer to its head.

**P2.** Write a function that removes all consecutive repetitions of an element in doubly linked list by a pointer to its head.

**P3.** Problems from last week but for DLL.

**P4.** Flatten a multilevel doubly linked list - each node could have a child that is a DLL so we need to flatten everything following the example:
1 <-> 2 <-> 3 <-> 4
      |     |
      |     10
      |
      5 <-> 6 <-> 7
            |
            8 <-> 9
Result: 1 <-> 2 <-> 5 <-> 6 <-> 8 <-> 9 <-> 7 <-> 3 <-> 10 <-> 4

**P5.** Write a function that aggregates the elements of a circular list.
```cpp
template <typename T, typename R>
T aggregate(Node<T> *head, std::function<R(T)> aggr, const R& init_value);
```

**P6.** Imagine $n$ people in a circle labeled from $1$ to $n$. Starting from the first remove the $k^{th}$ next and continue until only one remains. Print the label of the last standing person.