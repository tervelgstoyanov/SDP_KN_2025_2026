#include <iostream>
#include <functional>
#include <string>
#include <cassert>

template <typename T>
struct Node {
    T value;
    Node* next;

    Node(const T& val = T{}, Node* next = nullptr)
        : value(val), next(next) {}
};

template <typename T>
void deallocate(Node<T>*& head)
{
    while (head)
    {
        Node<T>* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    // head = nullptr;
}

template <typename T>
void print(Node<T>* head)
{
    while (head)
    {
        std::cout << head->value << ' ';
        head = head->next;
    }
    std::cout << "nullptr\n";
}

template <typename T>
T foldl(Node<T>* head, const std::function<T(T, T)>& func, const T& neutral)
{
    T result = neutral;

    while (head)
    {
        result = func(result, head->value);
        head = head->next;
    }

    return result;
}

std::string append(const std::string& x, const std::string& y)
{
    return x + y;
}
Node<int>* create(int from, int to, Node<int>*& new_tail)
{
    int sign = (to - from > 0 ? 1 : -1);

    Node<int>* new_head = new Node<int>(from + sign),
              *it = new_head;
    
    for (int i = from + 2 * sign; i != to; i += sign)
    {
        it->next = new Node<int>(i);
        it = it->next;
    }
    new_tail = it;

    return new_head;
}
void add_in_between(Node<int>* head)
{
    if (head == nullptr || head->next == nullptr)
        return;
    
    while (head->next)
    {
        int from = head->value, to = head->next->value;
        if (std::abs(to - from) > 1)
        {
            Node<int> *new_tail, *new_head = create(from, to, new_tail);

            new_tail->next = head->next;
            head->next = new_head;
            head = new_tail->next;
        }
        else head = head->next;
    }
}

void remove(Node<int>* head)
{
    if (
        head == nullptr ||
        head->next == nullptr ||
        head->next->next == nullptr
    )
        return;
    
    int prevprev = head->value, prev = head->next->value;
    Node<int>* prev_valid = head->next;
    head = head->next->next;

    while (head)
    {
        if (head->value != prevprev * prev)
        {
            Node<int>* toDelete = head;
            head = head->next;
            delete toDelete;

            prev_valid->next = head;
            continue;
        }

        prevprev = prev;
        prev = head->value;
        
        prev_valid = head;
        head = head->next;
    }
}

int main()
{
    // Node<std::string>* head = new Node<std::string>("a");
    // Node<std::string>* el1 = new Node<std::string>("b");
    // Node<std::string>* el2 = new Node<std::string>("c");
    // Node<std::string>* el3 = new Node<std::string>("d");
    // Node<std::string>* el4 = new Node<std::string>("e");

    // head->next = el1;
    // el1->next =el2;
    // el2->next =el3;     
    // el3->next =el4;

    // print<std::string>(head);

    // std::string result = foldl<std::string>(head, append, "");
    // std::cout << result << std::endl;
    
    // print<std::string>(head);
    // deallocate<std::string>(head);
    // assert(head == nullptr);

    // Node<int>* head = new Node<int>(-1);
    // Node<int>* el1 = new Node<int>(-8);
    // Node<int>* el2 = new Node<int>(6);
    // Node<int>* el3 = new Node<int>(-2);
    
    // head->next = el1;
    // el1->next =el2;
    // el2->next =el3;

    // print<int>(head);
    // add_in_between(head);
    // print<int>(head);

    Node<int>* head = new Node<int>(1);
    Node<int>* el1 = new Node<int>(2);
    Node<int>* el2 = new Node<int>(2);
    Node<int>* el3 = new Node<int>(3);
    Node<int>* el4 = new Node<int>(5);
    Node<int>* el5 = new Node<int>(4);
    
    head->next = el1;
    el1->next =el2;
    el2->next =el3;
    el3->next =el4;
    el4->next =el5;
    
    print<int>(head);
    remove(head);
    print<int>(head);


    return 0;
}