#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>

// DAG - directed graph with no cycles
// Topological sorting for Directed Acyclic Graph (DAG) is a linear
// ordering of vertices such that for every directed edge u-v,
// vertex u comes before v in the ordering.

void addEdge( std::vector<std::list<int>> &g,int v, int u, bool isDirected = true)
{
    g[v].push_back(u);
    if (!isDirected)
    {
        g[u].push_back(v);
    }
}

void topoSortHelp(std::vector<std::list<int>> g, int curr, std::vector<bool> &visited, std::stack<int> &s)
{
    if (visited[curr])
    {
        return;
    }
    visited[curr] = true;

    for (int neighbour : g[curr])
    {
        topoSortHelp(g, neighbour, visited, s);
    }

    s.push(curr); // where the recursion is coming back
}

std::vector<int> topoSort(std::vector<std::list<int>> &g)
{
    std::stack<int> st;
    std::vector<bool> visited(g.size(),false); // !!
    std::vector<int> res;

    for (int i = 0; i < g.size(); i++)
    {
        topoSortHelp(g, i, visited, st);
    }

    while(!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    return res;
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
    std::vector<int> v = topoSort(g);
    for(int elem: v)
    {
        std::cout<<elem<<" ";
    }
}