#include <iostream>
#include <string>
#include <stack>

int findLongestValidSubexprLength(const std::string& expr)
{
    std::stack<int> st; // stack to store the beginnings of subexpressions
    st.push(-1); // add bottom to safely count
    int result = 0;

    for (int i = 0; i < expr.size(); ++i)
    {
        if (expr[i] == '(')
            st.push(i); // each '(' could be a beginning of a valid subexpression
        else // current symbol is ')'
        {
            st.pop(); // pop always
            if (st.empty())
                st.push(i); 
            else
                result = std::max(result, i - st.top());
        }
    }

    return result;
}

int main()
{
    std::string expr;
    std::getline(std::cin, expr);

    std::cout << findLongestValidSubexprLength(expr) << std::endl;
    return 0;
}