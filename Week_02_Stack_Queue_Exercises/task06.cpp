#include <iostream>
#include <stack>
#include <queue>

void reverseFirstK(std::queue<int>& q, int k)
{
    std::stack<int> st;

    for (int i = 1; i <=k ; ++i)
    {
        st.push(q.front());
        q.pop();
    }

    for (int i = 1; i <= k; ++i) // while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    int last_count = q.size() - k; 
    for (int i = 1; i <= last_count; ++i)
    {
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::queue<int> q;
    int temp;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> temp;
        q.push(temp);
    }

    reverseFirstK(q, k);
    while (!q.empty())
    {
        std::cout << q.front() << ' ';
        q.pop();
    }
    std::cout << std::endl;
}