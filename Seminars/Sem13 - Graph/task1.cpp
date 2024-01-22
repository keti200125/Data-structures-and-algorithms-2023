#include <iostream>
#include <vector>
#include <list>
#include <queue>
// weights

struct Edge
{
    int vertex;
    int weight;

    Edge(int v = 0, int w = 0) : vertex{v}, weight{w} {}
};

struct Graph
{
    std::vector<std::list<Edge>> components;

    Graph(int size) : components(size) {}

    void addEdge(int from, int to, int weight, bool isDirected = true)
    {
        components[from].push_back({to, weight});
        if (!isDirected)
        {
            components[to].push_back({from, weight});
        }
    }
};

struct distPair
{
    int vert;
    int dist; // distance

    bool operator<(const distPair& other) const
    {
        return dist > other.dist;
    }

};

// nlgn 

void dijkstra(const Graph& g,int start) 
{
    std::vector<bool> visited(g.components.size(),false);
    std::vector<int> parents(g.components.size(),-1);
    std::vector<int> distance(g.components.size(), INT_MAX);
    std::priority_queue<distPair> q;
    q.push({start,0});

    while(!q.empty())
    {
        distPair curr = q.top();
        q.pop();
        int currVert = curr.vert;

        if(visited[currVert])
        {
            continue; // breaks one iteration in a loop
        }

        visited[currVert] =true; 
        distance[currVert]=curr.dist;

        for(Edge edge: g.components[currVert]) 
        {
            if((!visited[edge.vertex]) && (edge.weight+distance[currVert]<distance[edge.vertex]))
            {
                distance[edge.vertex]=edge.weight+distance[currVert];
                parents[edge.vertex]=currVert;
                q.push({edge.vertex,distance[edge.vertex]});
            }
        }

    }

     for (size_t i = 0; i < g.components.size(); i++)
    {
        std::cout << i << " dist is " << distance[i] << std::endl;
    }
}

// n^2
void dijkstrawithoutPriorityQueue(const Graph& g, int source)
{
    std::vector<int> distance(g.components.size(), INT_MAX);
    std::vector<bool> visited(g.components.size(),false);
    std::vector<int> parents(g.components.size(), -1);

    distance[source] = 0;

    for (size_t i = 0; i < g.components.size(); i++)
    {
        int currVertex = -1;
        int currDist = INT_MAX;

        for (size_t vertex = 0; vertex < g.components.size(); vertex++)
        {
            if (!visited[vertex] && distance[vertex] < currDist)
            {
                currVertex = vertex;
                currDist = distance[vertex];
            }
        }

        visited[currVertex] = true;

        for (Edge edge : g.components[currVertex])
        {
            if (!visited[edge.vertex] && distance[currVertex] + edge.weight < distance[edge.vertex])
            {
                distance[edge.vertex] = distance[currVertex] + edge.weight;
                parents[edge.vertex] = currVertex;
            }
        }
    }

    for (size_t i = 0; i < g.components.size(); i++)
    {
        std::cout << i << " dist is " << distance[i] << std::endl;
    }

}

int main()
{
    Graph g(9);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    dijkstra(g,0);
    std::cout<<std::endl;

    dijkstrawithoutPriorityQueue(g,0);

}
