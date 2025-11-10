#include <iostream>

template <typename T>
struct Node {
    T value;
    Node *prev, *next;

    Node(
        const T& val = T{},
        Node *prev = nullptr,
        Node *next = nullptr
    ) :
        value(val),
        prev(prev),
        next(next) {}
};

template <typename T>
void print(Node<T>* head)
{
    while (head != nullptr)
    {
        std::cout << head->value << " <-> ";
        head = head->next;
    }
    std::cout << "nullptr\n";
}

template <typename T>
void deallocate(Node<T>*& head)
{
    while (head != nullptr)
    {
        Node<T>* to_delete = head;
        head = head->next;
        delete to_delete;
    }
}

template <typename T>
void remove_concecutives(Node<T>*& head)
{
    if (
        head == nullptr ||
        (head->prev == nullptr && head->next == nullptr)
    ) return;

    Node<T> *curr = head, *next = head->next;
    while (next != nullptr)
    {
        if (curr->value != next->value)
        {
            curr = next;
            next = next->next;
        }
        else
        {
            Node<T> *nextnext = next->next; // nullptr ili nqkoi node
            curr->next = nextnext;
            if (nextnext != nullptr)
                nextnext->prev = curr;
            
            delete next;
            next = nextnext;
        }
    }
}

int main()
{
    Node<int> *el1 = new Node<int>(1);
    Node<int> *el2 = new Node<int>(1);
    Node<int> *el3 = new Node<int>(1);
    Node<int> *el4 = new Node<int>(2);
    Node<int> *el5 = new Node<int>(2);
    Node<int> *el6 = new Node<int>(3);
    Node<int> *el7 = new Node<int>(3);

    el1->next = el2;
    el2->prev = el1; el2->next = el3;
    el3->prev = el2; el3->next = el4;
    el4->prev = el3; el4->next = el5;
    el5->prev = el4; el5->next = el6;
    el6->prev = el5; el6->next = el7;
    el7->prev = el6;

    print<int>(el1);
    remove_concecutives<int>(el1);
    print<int>(el1);

    deallocate<int>(el1);

    return 0;
}