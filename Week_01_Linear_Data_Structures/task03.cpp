#include <iostream>
#include <stack>
#include <string>

bool is_opening(char c)
{
    return c == '(' || c == '[' || c == '{';
}
bool is_closing(char c)
{
    return c == ')' || c == ']' || c == '}';
}
bool is_right(char opened, char closed)
{
    return (
        (opened == '(' && closed == ')')
        || (opened == '[' && closed == ']')
        || (opened == '{' && closed == '}')
    );
}
bool is_valid(const std::string& expr)
{
    std::stack<char> st;

    for (const char& ch : expr)
    {
        if (is_closing(ch))
        {
            if (st.empty())
                return false;
            
            char last_opened = st.top();
            st.pop();
            
            if (!is_right(last_opened, ch))
                return false;
        }
        else if (is_opening(ch))
            st.push(ch);
        else
            return false;
    }

    return st.empty();
}

int main()
{
    std::string expr;
    std::getline(std::cin, expr);

    std::cout << is_valid(expr) << std::endl;

    return 0;
}