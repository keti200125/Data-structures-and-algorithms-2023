#include<iostream>
#include<list>
#include<vector>


void addEdge(int v,int u,std::vector<std::list<int>>& g,bool isDirected=false)
{
    g[v].push_back(u);

    if(!isDirected)
    {
        g[u].push_back(v);
    }
}

void dfsVisit( std::vector<std::list<int>>& g, int curr,std::vector<bool>& visited)
{
    if(visited[curr])
    {
        return;
    }

    visited[curr]=true;
    std::cout<<curr<<" ";

    for(int neighbour: g[curr])
    {
        dfsVisit(g,neighbour,visited);
    }
}

void dfs( std::vector<std::list<int>> g, int start)
{
    std::vector<bool> visited(g.size());
    dfsVisit(g,start,visited);


}



int main()
{
    std::vector<std::list<int>> g(3);
    addEdge(0,1,g);
    addEdge(1,2,g);

    dfs(g,2);

}