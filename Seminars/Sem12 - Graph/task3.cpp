#include <iostream>
#include <vector>
#include <list>

void addEdge(int v, int u, std::vector<std::list<int>> &g, bool isDirected = false)
{
    g[v].push_back(u);
    if (!isDirected)
    {
        g[u].push_back(v);
    }
}

void dfsSearch(const std::vector<std::list<int>>& g,std::vector<bool>& visited,int curr,int& sum, int& count)
{
    if(visited[curr]==true)
    {
        return;
    }
    visited[curr]=true;
    count++;
    sum+=curr;

    for(int neighbours: g[curr])
    {
        dfsSearch(g,visited,neighbours,sum,count);
    }
}

double sumOfEdgesInComponents(const std::vector<std::list<int>>& g)
{
    std::vector<bool> visited(g.size(),false);
    double bigSum=0;
    for(int i=0;i<g.size();i++)
    {
        int sum=0;
        int count=0;
        if(visited[i]==false)
        {
            dfsSearch(g,visited,i,sum,count);
            if(count>0)
            {
                bigSum+=double(sum)/count;
            }
        }

    }
    return bigSum;
}

int main()
{
    std::vector<std::list<int>> g(9);
    addEdge(7,8,g);
    addEdge(4,5,g);
    addEdge(4,6,g);
    addEdge(5,6,g);
    addEdge(2,1,g);
    addEdge(0,3,g);
    addEdge(0,1,g);
    addEdge(2,3,g);
    double sum=sumOfEdgesInComponents(g);
    std::cout<<sum;

}