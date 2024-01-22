#include <iostream>
#include <stack>

// Намерете n-то числи не Фибоначи използвайки стек вместо рекурсия
// 1 1 2 3 5 8 13 21
// 1
int fib(int num)
{
    if (num <= 1)
        return num;

    return fib(num - 1) + fib(num - 2);
}

int fibSTack(int num)
{
    if (num <= 1)
    {
        return num;
    }
    int res = 0;

    std::stack<int> st;
    st.push(num);

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        if (curr <= 1)
        {
            res += curr;
        }
        else
        {
            st.push(curr - 1);
            st.push(curr - 2);
        }
    }
    return res;
}

int main()
{
    std::cout << fib(9) << " " << fibSTack(9);
}