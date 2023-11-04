#include <iostream>
#include <stack>
#include <string>

// Вход: Низ състоящ се от отварящи и затварящи скоби.
// Изход: Дали скобите в този низ са балансирани

bool isBalanced(const std::string &str)
{
    std::stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (s.empty() 
            || (str[i] == ')' && s.top() != '(') 
            || (str[i] == ']' && s.top() != '[') 
            || (str[i] == '}' && s.top() != '{'))
            {
                return false;
            }

            s.pop();
        }
    }

    return s.empty();
}

int main()
{
    std::cout<<isBalanced("{fggefrw[]}а()")<<" "; //valid
    std::cout<<isBalanced("{[}]")<<" "; //not valid
    std::cout<<isBalanced("(ddddwsds")<<" "; //not valid
}