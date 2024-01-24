#include <iostream>
#include<queue>

template <class T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(const T &elem, Node<T> *l = nullptr, Node<T> *r = nullptr) : data{elem}, left{l}, right{r} {}
};

struct Employee
{
    std::string name;
    size_t daysWorkExp;
    int salary;

    Employee(const std::string &n, size_t w, int s) : name{n}, daysWorkExp{w}, salary{s} {}

    bool operator<(const Employee &other) const
    {
        if (this->daysWorkExp < other.daysWorkExp)
        {
            return true;
        }
        else if (this->daysWorkExp > other.daysWorkExp)
        {
            return false;
        }
        else // ==
        {
            for (int i = 0; i < (std::min(this->name.size(), other.name.size())); i++)
            {
                if (this->name[i] == other.name[i])
                {
                    continue;
                }
                else if (this->name[i] < other.name[i])
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }

            return name.size() < other.name.size();
        }
    }
};

bool inputEmployee(Node<Employee> *&r, const Employee &e)
{
    if (r == nullptr)
    {
        r = new Node{e};
        return true;
    }
    else if (r->data.name == e.name)
    {
        throw std::invalid_argument("The employee is alredy in");
        return false;
    }
    else if (r->data < e)
    {
        inputEmployee(r->left, e);
    }
    else
    {
        inputEmployee(r->right, e);
    }

    return false;
}

// task b)

template <class T>
size_t findSize(Node<T> *r)
{
    if (r == nullptr)
    {
        return 0;
    }

    return 1 + findSize(r->left) + findSize(r->right);
}

void findMedianHelp(Node<Employee> *r, int &stopper, int &med)
{
    if (r == nullptr)
    {
        return;
    }

    findMedianHelp(r->left, stopper, med);
    stopper = stopper - 1;
    if (stopper == 0)
    {
        med = r->data.daysWorkExp;
        return;
    }
    findMedianHelp(r->right, stopper, med);
}

int findMedian(Node<Employee> *r)
{
    int size = findSize(r);
    int med1 = 0;
    int med2 = 0;
    int size1 = size / 2;
    int size2 = size / 2 + 1;
    findMedianHelp(r, size1, med1);
    findMedianHelp(r, size2, med2);
    if (size % 2 == 0)
    {
        return (med1 + med2) / 2;
    }
    return med2;
}

void inorderTraversal(Node<Employee> *r)
{
    if (r == nullptr)
    {
        return;
    }

    inorderTraversal(r->left);
    std::cout << r->data.name << " ";
    inorderTraversal(r->right);
}

int levelMedium(Node<Employee> *r, int level)
{
    if(r==nullptr)
    {
        return 0;
    }
    if (level == 1)
    {
        return r->data.salary;
    }
    std::queue<Node<Employee>*> q;
    int sum=0;
    int elems=0;
    q.push(r);
    q.push(nullptr);

    while(!q.empty())
    {
        Node<Employee>* curr =q.front();
        q.pop();

        if(curr==nullptr)
        {
            level --;
            if(level==0)
            {
                return sum/elems;

            }
            if(!q.empty())
            {
                q.push(nullptr);
            }
            sum=0;
            elems=0;
        }
        else
        {
            elems++;
            sum+=curr->data.salary;
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
        }
    }

    return 0;
}

int main()
{
    Employee e1("Keti", 30, 2000);    
    Employee e2("Stoycho", 50, 3000); 
    Employee e3("Miro", 20, 1800);    
    Employee e4("Angel", 100, 5000);
    Employee e5("Yavor", 40, 2500);
    Employee e6("Ivana", 10, 500);

    Node<Employee> *tree;

    try
    {
        inputEmployee(tree, e1);
        inputEmployee(tree, e2);
        // inputEmployee(tree,e3);
        inputEmployee(tree, e4);
        inputEmployee(tree, e5);
        inputEmployee(tree, e6);
        // inputEmployee(tree,e1);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what();
        return -1;
    }

    inorderTraversal(tree);

    // std::cout<<"\n"<<findSize(tree);
    std::cout << "\n"<< findMedian(tree);

    std::cout<<"\n"<<levelMedium(tree,2);

        // Keti
    //Stoycho   //Ivana
   
}