#include <iostream>
#include <stack>

template <typename Type>
void print_stack(const std::stack<Type>& st)
{
    std::stack<Type> copy = st;
    while (!copy.empty())
    {
        std::cout << copy.top() << ' ';
        copy.pop();
    }
    std::cout << std::endl;

    return;
}

template <typename Type>
void reverse_stack(std::stack<Type>& st)
{
    std::stack<Type> copy;
    while (!st.empty())
    {
        copy.push(st.top());
        st.pop();
    }

    st = copy;
}

int main()
{
    unsigned int n;
    std::cin >> n;

    std::stack<int> st;
    int temp;
    for (std::size_t it = 0; it < n; ++it)
    { 
        std::cin >> temp;
        st.push(temp);
    }
    
    print_stack(st);
    reverse_stack(st);
    print_stack(st);

    return 0;
}