#include <iostream>
#include <string>
#include <stack>

std::string removeDuplicates(const std::string& s)
{
    std::stack<char> st;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (st.empty() || st.top() != s[i]) st.push(s[i]);
        else if (!st.empty() && st.top() == s[i]) st.pop();
    }

    std::string result;
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}

int main()
{
    std::string s;
    std::getline(std::cin, s);

    std::cout << removeDuplicates(s) << std::endl;
    return 0;
}