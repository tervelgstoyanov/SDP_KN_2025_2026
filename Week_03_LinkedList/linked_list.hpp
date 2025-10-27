#pragma once
#ifndef _SINGLY_LINKED_LIST_
#define _SINGLY_LINKED_LIST_

#include <iostream>
#include <cstddef>

template <class T>
class SLL {
    struct Node {
        T value;
        Node* next;

        Node(const T& val = T{}, Node* next = nullptr)
            : value(val), next(next) {}
    };
    Node *head, *tail;
    std::size_t size;

public:
    SLL();
    SLL(const SLL& other);
    SLL(SLL&& other);
    SLL& operator=(const SLL& other);
    SLL& operator=(SLL&& other);
    ~SLL();

    const T& front() const;
    const T& back() const;
    const T& at(std::size_t pos) const;

    class Iterator;
    Iterator begin();
    Iterator end() const;

    bool empty() const;
    std::size_t size() const;

    void push_front(const T& new_value);
    void push_back(const T& new_value);
    void push_at(std::size_t pos, const T& new_value);
    void push_after(Iterator it, const T& new_value);

    void pop_front();
    void pop_end();
    T pop_at(std::size_t pos);
    void pop_after(Iterator it);

    void append(const SLL& other);
    SLL& operator + (const SLL& other) const;
    SLL& operator += (const SLL& other);

    void reverse();
    bool is_sorted() const;
    
    template <class Func>
    void map(const Func& func);
    template <class Pred>
    void filter(const Pred& pred);

private:
    void copy(const SLL& other);
    void deallocate(Node*& head);
};

template <class T>
class SLL<T>::Iterator {
    friend class SLL<T>;

    SLL<T>::Node *ptr;
    const SLL<T>& owner;

    Iterator(SLL<T>::Node *ptr, const SLL<T>& creator)
        : ptr(ptr), owner(creator) {}

public:
    bool valid() const { return ptr; }
    T& operator * () { return ptr->value; }
    T* operator -> () { return &ptr->value; }
    
    const T& operator * () { return ptr->value; }
    const T* operator -> () { return &ptr->value; }

    Iterator& operator ++ ()
    {
        ptr = ptr->next;
        return *this;
    }
    Iterator operator ++ (int)
    {
        Iterator copy = *this;
        ++*this;
        return copy;
    }
    bool operator == (const Iterator& other) const
    {
        return ptr == other.ptr;
    }
    bool operator != (const Iterator& other) const
    {
        return !(*this == other);
    }
};
template<class T>
inline typename SLL<T>::Iterator SLL<T>::begin()
{
    return Iterator(head, *this);
}

template<class T>
inline typename SLL<T>::Iterator SLL<T>::end() const
{
    return Iterator(nullptr, *this);
}

template <class T>
inline void SLL<T>::copy(const SLL<T>& other)
{
    Node dummy;
    Node *it = &other, *curr = other.head;

    tail = head = nullptr;
    size = 0;

    while (curr != nullptr)
    {
        it->next = new Node(curr->value);
        it = it->next;
        curr = curr->next;
    }
    head = dummy.next;
    tail = head ? it : nullptr;
    size = other.size;
}
template <class T>
inline void SLL<T>::deallocate(Node*& head)
{
    for (Node* it = head; it != nullptr; )
    {
        Node* const detach = it;
        it = it->next;
        delete detach;
    }

    head = nullptr;
}

template <class T>
inline SLL<T>::SLL()
    : head(nullptr), tail(nullptr), size(0) {}
template<class T>
inline SLL<T>::SLL(const SLL& other)
    :SLL()
{
    copy(other);
}
template<class T>
inline SLL<T>::SLL(SLL&& other)
    :SLL()
{
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(size, other.size);
}
template<class T>
inline SLL<T>& SLL<T>::operator = (const SLL<T>& other)
{
    if (this != &other) {
        deallocate(head);
        copy(other);
    }

    return *this;
}
template<class T>
inline SLL<T>& SLL<T>::operator = (SLL<T>&& other)
{
    if (this != &other) {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(size, other.size);
    }
    return *this;
}
template<class T>
inline SLL<T>::~SLL()
{
    deallocate(head);
}

template <class T>
inline const T& SLL<T>::at(std::size_t pos) const
{
    if (empty() || pos >= size()) {
        throw std::invalid_argument("Index out of bounds\n");
    }

    if (pos == size() - 1)
        return tail->value;

    const Node* it = head;
    for (std::size_t i = 0; i < pos; ++i, it = it->next)
        ;
    return it->value;
}
template<class T>
inline const T& SLL<T>::front() const
{
    return at(0);
}

template< class T>
inline const T& SLL<T>::back() const
{
    return at(size - 1);
}

template<class T>
inline size_t SLL<T>::size() const
{
    return size;
}

template <class T>
inline void SLL<T>::push_at(std::size_t pos, const T& new_value)
{
    if (pos > size())
        throw std::invalid_argument("Index out of bounds\n");

    if (pos == 0)
    {
        head = new Node(new_value, head);
        if (empty()) tail = head;
    }
    else if (pos == size())
    {
        tail->next = new Node(new_value);
        tail = tail->next;
    }
    else
    {
        Node* it = head;
        for (std::size_t i = 0; i < pos - 1; ++i, it = it->next);
        it->next = new Node(new_value, it->next); 
    }

    ++size;
}

template <class T>
inline void SLL<T>::push_after(Iterator it, const T& new_value)
{
    if (&it.owner != this)
        throw std::invalid_argument("Iterator from different list\n");
    if (!it.ptr)
        throw std::invalid_argument("Bad iterator\n");
    
    it.ptr->next = new Node(new_value, it.ptr->next);
    if (it.ptr == tail)
        tail = it.ptr->next;
    ++size;
}
#endif