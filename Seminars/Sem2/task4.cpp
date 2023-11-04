#include <iostream>
#include <stack>

// 217
//  Да се сортира стек като използвате само един допълнителен стек.

void sortStack(std::stack<int> &first)
{
    std::stack<int> second;
    int elemOne = 0;
    int elemTwo = 0;
    while (!first.empty())
    {
        elemOne = first.top();
        first.pop();

        if (second.empty())
        {
            second.push(elemOne);
        }
        else
        {
            elemTwo = second.top();
            while (elemTwo > elemOne)
            {
                first.push(elemTwo);
                second.pop();
                if (!second.empty())
                {
                    elemTwo = second.top();
                }
                else
                {
                    elemTwo = elemOne;
                }
            }
            second.push(elemOne);
        }
    }

    while (!second.empty())
    {
        first.push(second.top());
        second.pop();
    }
}

void sortStackTwo(std::stack<int> &first)
{
    std::stack<int> second;
    int currentElement = 0;
    while (!first.empty())
    {
        currentElement = first.top();
        first.pop();

        while (!second.empty() && second.top() > currentElement)
        {
            first.push(second.top());
            second.pop();
        }
        second.push(currentElement);
    }

    while (!second.empty())
    {
        first.push(second.top());
        second.pop();
    }
}

void stackPrint(std::stack<int> st)
{
    while (!st.empty())
    {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;
}

int main()
{
    std::stack<int> st;
    st.push(8);
    st.push(2);
    st.push(4);
    st.push(1);
    st.push(5);
    st.push(3);

    stackPrint(st);
    sortStackTwo(st);
    stackPrint(st);
}