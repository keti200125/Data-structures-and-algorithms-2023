#include<iostream>
#include<vector>
#include<list>
#include<queue>

void addEdge(int v, int u, std::vector<std::list<int>> &g, bool isDirected = false)
{
    g[v].push_back(u);
    if (!isDirected)
    {
        g[u].push_back(v);
    }
}

void bfsSearch(std::vector<std::list<int>>& g,int start,std::vector<bool>& visited)
{
    std::queue<int> q;
    q.push(start);

    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        if(visited[curr]==true)
            continue;

        visited[curr]=true;
        std::cout<<curr<<" ";

        for(int neighbour: g[curr])
        {
            if(!visited[neighbour])
            {
                q.push(neighbour);
            }
        }
        
    }

}


void bfs(std::vector<std::list<int>> g)
{
    std::vector<bool> visited(g.size(), false);

    for(int i;i<g.size();i++)
    {
        if(!visited[i])
        {
            bfsSearch(g,i,visited);
        }
    }
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
    bfs(g);

}