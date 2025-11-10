template <typename T>
struct TripleNode {
    T value;
    TripleNode *prev, *next;
    TripleNode *child;

    TripleNode(
        const T& val = T{},
        TripleNode *prev = nullptr,
        TripleNode *next = nullptr,
        TripleNode *child = nullptr
    ) :
        value(val),
        prev(prev),
        next(next),
        child(child) {}
};

template <typename T>
struct DoubleNode {
    T value;
    DoubleNode *prev, *next;

    DoubleNode(
        const T& val = T{},
        DoubleNode *prev = nullptr,
        DoubleNode *next = nullptr
    ) :
        value(val),
        prev(prev),
        next(next) {}
};

template <typename T>
void helper(TripleNode<T> *_head, DoubleNode<T>*& head, DoubleNode<T>*& tail)
{
    if (_head == nullptr)
        return;
    
    DoubleNode<T> *curr = new DoubleNode<T>(_head->value);
    if (head == nullptr)
        head = tail = curr;
    else
    {
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }

    if (_head->child != nullptr)
        helper(_head->child, head, tail);
    
    helper(_head->next, head, tail);
}

template <typename T>
DoubleNode<T>* flatten(const TripleNode<T>* head)
{
    DoubleNode<T> *new_head = nullptr, *new_tail = nullptr;
    helper(head, new_head, new_tail);
    
    return new_head;
}