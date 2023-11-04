#include<iostream>
#include<queue>
#include<vector>

bool sameRows(const std::vector<int>& v)
{
    std::queue<int> q;

    for(size_t i=0;i<v.size();i++)
    {
        if(q.empty())
        { 
            q.push(v[i]);
            continue;
        } 
        if(v[i]+q.front()==0)
        {
            q.pop();
        }
        else
        {
            q.push(v[i]);
        }
    }
    return q.empty();
}


int main()
{
    std::vector<int> v{1,5, -1, 4, -5, 9, 8, -4, -9, 18, -8, -18, -7, 7};
    std::cout<<sameRows(v)<<std::endl;
    std::vector<int> v2{1, -1, 2, -2, 3, 3};
    std::cout<<sameRows(v2);

}