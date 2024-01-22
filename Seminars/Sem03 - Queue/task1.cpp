#include <iostream>
#include <queue>
#include <string>

void binaryNumbers(size_t n)
{
    std::queue<std::string> q;
    q.push("1");
    while(n)
    {
        std::string currNum=q.front();
        q.pop();
        std::cout<<currNum<<" ";

        q.push(currNum+"0");
        q.push(currNum+"1");

        n--;
    }
    std::cout<<std::endl;
}

void binaryNumbersWithInt(size_t n)
{
    std::queue<int> q;
    q.push(1);
    while(n)
    {
        int currNum=q.front();
        q.pop();
        std::cout<<currNum<<" ";

        q.push(currNum*10);
        q.push(currNum*10 +1);

        n--;
    }
}


int main()
{
    binaryNumbers(10);
    binaryNumbersWithInt(10);
}