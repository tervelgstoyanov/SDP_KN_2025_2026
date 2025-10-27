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

template <typename T>
void appendMirroredCopy(Node<T> *head)
{
    if (head == nullptr)
        return;
    
    Node<T> *mirrored_head = nullptr;

    while (head->next != nullptr)
    {
        mirrored_head = new Node(head->value, mirrored_head);
        head = head->next;
    }
    head->next = new Node(head->value, mirrored_head);
}

template <typename T>
Node<T>* getMiddle(Node<T>* head)
{
    if (head == nullptr || head->next == nullptr) return head;

    Node<T>* fast_ptr = head;
    while (fast_ptr->next != nullptr && fast_ptr->next->next != nullptr)
    {
        head = head->next;
        fast_ptr = fast_ptr->next->next;
    }
    return head;
}

int main()
{
    const int x = 5, y = 6, z = 7;
    Node<int> *head = new Node<int>(x);
    Node<int> *it = head;
    for (int i = 0; i < 4; ++i)
    {
        it->next = new Node<int>(i);
        it = it->next;
    }

    print<int>(head);
    std::cout << getMiddle(head)->value << std::endl;
    // const int a = 1, b = 2, c = 3;
    // Node<int> *head2 = new Node<int>(a, new Node<int>(b, new Node<int>(c)));

    // print(head2->next); // 2 3 nullptr

    deallocate<int>(head);
    //deallocate<int>(head2);

    return 0;
}