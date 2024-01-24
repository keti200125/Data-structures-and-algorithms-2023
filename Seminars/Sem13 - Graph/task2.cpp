#include <iostream>
#include <vector>
#include <list>
#include <map>

template <typename T>
struct Node
{
    T data;
    Node *left;
    Node *right;

    Node(const T &data, Node *left = nullptr, Node *right = nullptr) : data(data), left(left), right(right){};
};

struct Graph
{
    // трябва да имаме operator<() дефиниран за типа, представляващ ключ,
    // ако вместо тип char имаме тип Edge например

    std::map<char, std::list<char>> components;

    void addEdge(char from, char to)
    {
        components[from].push_back(to);
    }
};

void findPaths(const Node<char> *r, std::string &currPath, std::vector<std::string> &allPaths)
{
    if (r == nullptr)
    {
        return;
    }

    currPath.push_back(r->data);

    if (r->left == nullptr && r->right == nullptr)
    {
        allPaths.push_back(currPath);
        currPath.pop_back();
        return;
    }

    findPaths(r->left, currPath, allPaths);
    findPaths(r->right, currPath, allPaths);

    currPath.pop_back();
}

bool pathInGraph(const Graph &g, const std::string &path)
{
    std::map<char, std::list<char>>::const_iterator it = g.components.find(path[0]);

    if (it == g.components.end())
    {
        return false;
    }

    for (int i = 1; i < path.size(); i++)
    {
        if (it == g.components.end())
        {
            return false;
        }
        const std::list<char>& listOfNeighbours = (*it).second;
		bool found = false;

        for(char neighbour: listOfNeighbours)
        {
            if(neighbour==path[i])
            {
                found = true;
                break;
            }
        }
        if(!found)
        {
            return false;
        }
        it = g.components.find(path[i]);
    }

    return true;
}

void samePath(const Graph& g, const Node<char> *r)
{
    std::vector<std::string> allPaths;
    std::string currPath = "";

    findPaths(r, currPath, allPaths);
    

    for (int i = 0; i < allPaths.size(); i++)
    {
        if(pathInGraph(g,allPaths[i]))
        {
            std::cout<<allPaths[i];
            return;
        }
    }

    std::cout<<"No world :(";
}

int main()
{
    Node<char> *root = new Node<char>('a');
    Node<char> *n1 = new Node<char>('e');
    Node<char> *n2 = new Node<char>('f');
    Node<char> *n3 = new Node<char>('d');
    Node<char> *n4 = new Node<char>('g');
    Node<char> *n5 = new Node<char>('c');
    Node<char> *n6 = new Node<char>('b');
    Node<char> *n7 = new Node<char>('h');
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n5;
    n3->left = n6;
    n5->left = n7;

    Graph g;
    g.addEdge('a', 'f');
    g.addEdge('a', 'd');
    g.addEdge('b', 'h');
    g.addEdge('c', 'h');
    g.addEdge('d', 'e');
    g.addEdge('e', 'h');
    g.addEdge('f', 'h');
    g.addEdge('f', 'c');
    g.addEdge('g', 'b');
    g.addEdge('g', 'e');

    samePath(g, root);
}
