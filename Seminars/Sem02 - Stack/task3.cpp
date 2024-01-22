#include <iostream>
#include <stack>
#include <string>

//not done

bool isOpenningBracket(char ch)
{
    return (ch == '(' || ch == '[' || ch == '{');
}
bool isClosingBracket(char ch)
{
    return (ch == ')' || ch == ']' || ch == '}');
}


// {]} 
bool solve(const std::string &str)
{
    std::stack<char> s;
    size_t changes = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (isOpenningBracket(str[i]))
        {
            s.push(str[i]);
        }
        else if (isClosingBracket(str[i]))
        {
            if (s.empty())
            {
                if (changes == 0)
                {
                    changes++;
                }
                else
                {
                    return false;
                }
            }
            else if ((str[i] == ')' && s.top() != '(') || (str[i] == ']' && s.top() != '[') ||
                     (str[i] == '}' && s.top() != '{'))
            {
                if (changes == 0)
                {
                    changes++;
                    s.pop();
                    i--;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                s.pop();
            }
        }
    }
    
    if (changes == 0)
    {
        return s.size() <= 1;
    }

    return s.empty();
}

bool areCorresponding(char ch1, char ch2)
{
    return ch1 == '(' && ch2 == ')' || ch1 == '{' && ch2 == '}' || ch1 == '[' && ch2 == ']'; 
}

/*
bool solve(const std::string& str, bool seenMistake = false)
{
    std::stack<char> data;

    for(size_t i = 0; i < str.size(); ++i)
    {
        char ch = str[i];

        if(isOpenningBracket(ch))
        {
            data.push(ch);
        }
        else if(isClosingBracket(ch))
        {
            if(data.empty() || !areCorresponding(data.top(), ch))
            {
                if(!seenMistake)
                {
                    std::string copy = str;
                    copy.erase(copy.begin() + i);
                    return solve(copy, true);
                }

                return false;
            }

            data.pop();
        }
    }

    return (data.empty() && seenMistake) || (!seenMistake && data.size() <= 1);
}
*/

int main()
{
    std::cout << solve("))") << " ";      // false
    std::cout << solve("())") << " ";     // true
    std::cout << solve("()") << " ";      // true
    std::cout << solve("(()()()") << " "; // true
    std::cout << solve("()))") << " ";    // false
    std::cout << solve("([(])") << " ";   // true
    std::cout << solve("{]}") << " ";     // true
}
