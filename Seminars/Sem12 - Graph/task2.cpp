#include <iostream>
#include <vector>
#include <list>

void addEdge(int v,int u,std::vector<std::list<int>>& g,bool isDirected=false)
{
    g[v].push_back(u);

    if(!isDirected)
    {
        g[u].push_back(v);
    }
}

void dfsSearch(const std::vector<std::list<int>> &g, int curr, std::vector<bool> &visited)
{
    if (visited[curr])
        return;

    visited[curr] = true;

    for (int neighbour : g[curr])
    {
        dfsSearch(g, neighbour, visited);
    }
}

int components(const std::vector<std::list<int>> &g)
{
    std::vector<bool> visited(g.size(), false);
    int count = 0;

    for (int i = 0; i < g.size(); i++)
    {
        if (visited[i] == false)
        {
            dfsSearch(g, i, visited);
            count++;
        }
    }

    return count;
}

int main()
{
    std::vector<std::list<int>> g(4);
    addEdge(0,1,g);
    addEdge(1,2,g);

    std::cout<<components(g);


}