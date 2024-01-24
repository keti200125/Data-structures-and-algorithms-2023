#include<iostream>
#include<vector>

template<class T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(const T& elem,Node<T>* l=nullptr,Node<T>* r=nullptr):data{elem},left{l},right{r} {}
};

template<class T>
void free(Node<T>* root)
{
    if(root==nullptr)
    {
        return;
    }
    free(root->left);
    free(root->right);
    delete root;

}

template <class T>
void printBT(const std::string &prefix, const Node<T> *t, bool isLeft)
{
    if (t != nullptr)
    {
        std::cout << prefix;

       std::cout << (isLeft ? "|--" : "L--");
        std::cout << t->data << std::endl;

        printBT(prefix + (isLeft ? "|   " : "    "), t->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), t->right, false);
    }
}

template <class T>
void printTree(const Node<T> *t)
{
    printBT("", t, false);
    std::cout<<std::endl;
}

void maxi(const Node<char>* tree,std::vector<const Node<char>*>& v,bool& isGoodLevel,int& goodLevel)
{
    if(tree==nullptr)
    {
        return;
    }
    v.push_back(tree);
    v.push_back(nullptr);
    char lastElem=tree->data;
    int level=1;

    while(!v.empty())
    {
        const Node<char>* curr=v.front();
        v.erase(v.begin());        
        if(curr==nullptr)
        {
            if(isGoodLevel)
            {
                goodLevel=level;
            }
            level++;
            if(!v.empty())
                v.push_back(nullptr);
            
            lastElem = '\0';
            isGoodLevel = true;
        }
        else
        {
            if(lastElem>curr->data)
            {
                isGoodLevel=false;
            }
            lastElem=curr->data;
            if(curr->left)
            {
                v.push_back(curr->left);
            }
            if(curr->right)
            {
                v.push_back(curr->right);
            }

        }

    }
}
int maxLevel(const Node<char>* tree)
{
    std::vector<const Node<char>*> v;
    int goodLevel=1;
    bool isGoodLevel=1;
    maxi(tree,v,isGoodLevel,goodLevel);
    return goodLevel;
}



int main()
{
    Node<char>* tree=new Node<char>('F',new Node<char>('Q',new Node<char>('A'),new Node<char>
    ('D',new Node<char>('C'),new Node<char>('B'))),new Node<char>('G',nullptr,new Node<char>('I',new Node<char>('H'))));
    printTree(tree);
    std::cout<<maxLevel(tree);
    free(tree);

}