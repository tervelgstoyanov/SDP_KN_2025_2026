#include <iostream>
#include <string>
#include <stack>

int findNextChar(const std::string& s, int from, char c = '/')
{
    int i = from;
    while (i < s.size() && s[i] != '/')
        ++i;
    
    return i;
}

std::string simplify(const std::string& path)
{
    std::stack<std::string> st;
    int start = 0, end = -1;

    while(start < path.size())
    {
        end = findNextChar(path, start);
        std::string token = path.substr(start, end - start);

        if (token == "..")
        {
            if (!st.empty())
                st.pop();
        }
        else if (token != "" && token != ".")
            st.push(token);

        start = end + 1;
    }

    if (st.empty()) return "/";

    std::string result = "";
    while(!st.empty())
    {
        result = "/" + st.top() + result;
        st.pop();
    }

    return result;
}

int main()
{
    std::string path;
    std::getline(std::cin, path);

    std::cout << simplify(path) << std::endl;

    return 0;
}