#include <iostream>

template <typename T>
struct Node {
    T value;
    Node* next;

    Node(const T& val = T{}, Node* next = nullptr)
        : value(val), next(next) {}
};

template <typename T>
void deallocate(Node<T>* head)
{
    Node<T> *it = head;
    
    while (it != nullptr)
    {
        Node<T>* to_delete = it;
        it = it->next;
        delete to_delete;
    }
}

template <typename T>
void print(Node<T>* head)
{
    while (head != nullptr)
    {
        std::cout << head->value << ' ';
        head = head->next;
    }
    std::cout << "nullptr\n";
}

template <typename T>
unsigned int getOccurencesNumber(Node<T>* head, const T& target)
{
    Node<T> *it = head;
    unsigned int cnt = 0;

    while (it != nullptr)
    {
        if (it->value == target)
            ++cnt;
        it = it->next;
    }

    return cnt;
}

template <typename T>
void reverse(Node<T>*& head)
{
    if (head == nullptr || head->next == nullptr)
        return;
    
    Node<T>* prev = nullptr;

    while (head->next != nullptr)
    {
        Node<int>* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head->next = prev;
}

int main()
{
    const int x = 5, y = 6, z = 7;
    Node<int> *head = new Node<int>(x);
    Node<int> *el2 = new Node<int>(y);
    Node<int> *el3 = new Node<int>(z);

    head->next = el2;
    el2->next = el3;

    print<int>(head); // 5 6 7 nullptr

    reverse(head);
    print<int>(head);
    // print<int>(el3); // 7 nullptr
    
    const int a = 1, b = 2, c = 3;
    Node<int> *head2 = new Node<int>(a, new Node<int>(b, new Node<int>(c)));

    print(head2->next); // 2 3 nullptr

    deallocate<int>(head);
    deallocate<int>(head2);

    return 0;
}