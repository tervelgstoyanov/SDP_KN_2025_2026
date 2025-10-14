#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cassert>

int stringToNumber(const std::string& s)
{
    if (s[0] == '-') return (-1) * stringToNumber(s.substr(1));

    int result = 0;
    for (int i = 0; i < s.size(); ++i)
        result = result * 10 + (s[i] - '0');
    
    return result;
}
bool is_operator(const std::string& str)
{
    return
        str == "+" ||
        str == "-" ||
        str == "*" ||
        str == "/";
}
int getResult(const std::string& op, int n, int m)
{
    if (op == "+")
        return n + m;
    if (op == "-")
        return n - m;
    if (op == "*")
        return n * m;
    if (op == "/")
        return n / m;
    
    // unreachable code
    return -1;
}
int evalRPN(std::vector<std::string>& tokens)
{
    std::stack<int> st;

    for (const std::string& token : tokens)
    {
        if (!is_operator(token))
        {
            st.push(stringToNumber(token));
            continue;
        }
        int n = st.top(); st.pop();
        int m = st.top(); st.pop();

        st.push(getResult(token, m, n));
    }
    
    assert(st.size() == 1);
    return st.top();
}

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();
    
    std::vector<std::string> tokens(n);
    for (int i = 0; i < n; ++i)
        std::getline(std::cin, tokens[i]);
    
    std::cout << evalRPN(tokens) << std::endl;
    return 0;
}