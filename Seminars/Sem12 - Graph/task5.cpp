#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm> //reverse

void addEdge(int v, int u, std::vector<std::list<int>> &g, bool isDirected = false)
{
    g[v].push_back(u);
    if (!isDirected)
    {
        g[u].push_back(v);
    }
}

std::vector<int> getPath(std::vector<int>& parent,int start, int end)
{
    std::vector<int> res;

    if(parent[end]!=-1)
    {
        int curr=end;
        while(curr!=start)
        {
            res.push_back(curr);
            curr=parent[curr];
        }
        res.push_back(start);
    }

   std::reverse(res.begin(),res.end());
    return res;
}

std::vector<int> bfsShortestPath(std::vector<std::list<int>>& g,int start,int end)
{
    std::vector<bool> visited(g.size(),false);
    std::queue<int> q;
    q.push(start);
    std::vector<int> parent(g.size(),-1);

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
         
        visited[curr]=true;

         /*
        if(visited[curr])
            continue;
            */
        if(curr==end)
            break;
        
        for(int neighbour: g[curr])
        {
            if(!visited[neighbour])
            {
                q.push(neighbour);
            }
            if(parent[neighbour]==-1)
            {
                parent[neighbour]=curr;
            }

        }

    }

    return getPath(parent,start,end);
}

int main()
{
    std::vector<std::list<int>> g(5);
    addEdge(0,1,g);
    addEdge(0,2,g);
    addEdge(1,3,g);
    addEdge(3,4,g);
    addEdge(2,4,g);

    std::vector<int> v=bfsShortestPath(g,0,4);
    for(int i=0;i<v.size();i++)
    {
        std::cout<<v[i]<<" ";
    }
}