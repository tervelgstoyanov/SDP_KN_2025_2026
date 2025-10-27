### Data structures and Programming - Seminar
# Week 3 - Linked List implementation and examples

## Singly Linked List 
**Singly linked list** is a basic data structure. The main idea behind it is to easily manage a sequence of nodes in the memory - each node contains some value and a pointer to the next. The idea of a **node** is crucial so here is some definition in C++:
```cpp
template <class T>
struct Node {
    T value;
    Node* next;

    Node(const T& val = T{}, Node* next = nullptr);
};
```
There are more exotic types of linked lists, e.g. *doubly linked lists* and *circular linked lists*(next week).

## Implementation
See `linked_list.hpp`

## Linked list vs. Arrays?
Linked lists excell as multiple elements need to be added or deleted from the structure.

## Problems
**P1.** Given the head of a singly linked list and a value, write a function that returns the number of occurences of the value in the list.

**P2.** Write a function that reverses a linked list.

**P3.** Write a function that appends to a linked list its mirrored copy.

**P4.** Write a function that returns a pointer to the middle element in singly linked list.

**P5.** Finish the example implementation of singly linked list.