#include<iostream>
#include<vector>
#include<list>
#include<stack>

void addEdge( std::vector<std::list<int>> &g,int v, int u, bool isDirected = true)
{
    g[v].push_back(u);
    if (!isDirected)
    {
        g[u].push_back(v);
    }
}

bool hasCycleHelp(const std::vector<std::list<int>>& g,int curr, std::vector<bool>& visited,std::vector<bool>& visitedHere)
{
    if(visited[curr])
    {
        return false;
    }

    visited[curr]=true;
    visitedHere[curr]=true;

    for(int adj: g[curr])
    {
        if(visitedHere[adj])
        {
            return true;
        }
        if(hasCycleHelp(g,curr,visited,visitedHere))
        {
            return true;

        }
    }

    visitedHere[curr] = false; // if there is another path with cycle 

    return false;
}


bool hasCycle(std::vector<std::list<int>>& g)
{
    std::vector<bool> visited(g.size(),false);
    std::vector<bool> currVisited(g.size(),false);
    for(int i=0;i<g.size();i++)
    {
        if(hasCycleHelp(g,i,visited,currVisited))
        {
            return true;
        }
    }

    return false;
}




int main()
{
    std::vector<std::list<int>> g(12);
    
    addEdge(g, 0, 2);
    addEdge(g, 0, 4);
    addEdge(g, 0, 5);
    addEdge(g, 0, 8);
    addEdge(g, 1, 7);
    addEdge(g, 1, 3);
    addEdge(g, 2, 4);
    addEdge(g, 2, 5);
    addEdge(g, 2, 6);
    addEdge(g, 2, 7);
    addEdge(g, 3, 9);
    addEdge(g, 4, 6);
    addEdge(g, 8, 11);
    addEdge(g, 8, 10);

    std::cout << hasCycle(g);
}

