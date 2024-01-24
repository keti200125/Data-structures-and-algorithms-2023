#include<iostream>
#include<stack>
#include<queue>

bool isOperator(const char ch)
{
    return ((ch=='|') || (ch=='!') || (ch=='&'));
}

bool booleanType(char ch)
{
    return ch == 't';
}

bool isBooleanType(char ch)
{
    return ((ch=='t') || (ch=='f'));
}

bool evaluateCurr(char op,std::stack<bool>& st)
{ 
    bool toReturn =st.top();
    st.pop();
    if(op=='!')
    {
        return !(toReturn);
    }
    else if(op=='&')
    {
        while(!st.empty())
        {
            toReturn=st.top()&&toReturn;
            st.pop();
        }
    }
    else 
    {
         while(!st.empty())
        {
            toReturn=st.top()||toReturn;
            st.pop();
        }
    }
    return toReturn;
}



bool evaluate(const std::string& expr)
{
    std::stack<char> st;
    std::stack<bool> st2;
    
    for(int i=0;i<expr.size();i++)
    {
        if(isOperator(expr[i]) || isBooleanType(expr[i]))
        {
            st.push(expr[i]);
        }
        if(expr[i]==')')
        {
            while(isBooleanType(st.top()))
            {
                bool elem=booleanType(st.top());
                st2.push(elem);
                st.pop();
            }
            char op=st.top();
            st.pop();

            bool curr=evaluateCurr(op,st2);
            if(curr)
            {
                st.push('t');
            }
            else
            {
                st.push('f');
            }
        }
    }
    return st.top()=='t';
}



int main()
{
    std::cout<<evaluate("!(f)")<<std::endl;
    std::cout<<evaluate("|(f,t)")<<std::endl;
    std::cout<<evaluate("&(t,f)")<<std::endl;
    std::cout<<evaluate("|(&(t,f,t),!(t))")<<std::endl;


}