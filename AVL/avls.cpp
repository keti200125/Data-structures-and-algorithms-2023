#include <iostream>

template <class T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
    int height;

    Node(const T &elem, Node<T> *l = nullptr, Node<T> *r = nullptr, int h = 1) : data{elem}, left{l}, right{r}, height{h} {}
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

template<class T>
void rotateLeft(Node<T>*& root)
{
    Node<T>* toReturn=root->right;
    root->right=toReturn->left;
    toReturn->left=root;
    root=toReturn;
}

template<class T>
void rotateRight(Node<T>*& root)
{
    Node<T>* toReturn=root->left;
    root->left=toReturn->right;
    toReturn->right=root;
    root=toReturn;
}

template<class T>
void updateHeight(Node<T>* root)
{
    if(root=nullptr)
    {
        return;
    }

    root->height=std::max(updateHeight(root->left),updateHeight(root->right))+1;
}

template<class T>
size_t getHeight(const Node<T>* r)
{
    if(r==nullptr)
    {
        return 0;
    }

    return r->height

}

template<class T>
int getBalanceFactor(const Node<T>* r)
{
    if(r==nullptr)
    {
        return 0;
    }

    return getHeight(r->right) - getHeight(r->left);
}

template<class T>
void balanceRight(Node<T>*& root)
{
    int balanceFactorRoot=getBalanceFactor(root);
    int balanceFactorRight=getBalanceFactor(root->right);

    if root(balanceFactorRoot==2)
    {
        if(balanceFactorRight==-1)
        {
            rotateRight(root->right);
            updateHeight(root->right);
            updateHeight(root->right->right);
        }

        rotateLeft(root);
        updateHeight(root);
        updateHeight(root->left);
    }
}
template<class T>
int getBalanceFactor(const Node<T>* r)
{
    if(r==nullptr)
    {
        return 0;
    }

    return getHeight(r->right) - getHeight(r->left);
}

template<class T>
void balanceLeft(Node<T>*& root)
{
    int balanceFactorRoot=getBalanceFactor(root);
    int balanceFactorLeft=getBalanceFactor(root->right);

    if root(balanceFactorRoot==-2)
    {
        if(balanceFactorLeft==1)
        {
            rotateLeft(root->left);
            updateHeight(root->left)0;
            updateHeight(root->left->left);
        }

        rotateRight(root);
        updateHeight(root);
        updateHeight(root->right);
    }
}

template<class T>
Node<T>* findMinNode(Node<T>* root)
{
    if(root->left==nullptr)
    {
        return root;
    }

    findMinNode(root->left);
}
template<class T>
Node<T>* findMaxNode(Node<T>* root)
{
    if(root->right==nullptr)
    {
        return root;
    }

    findMinNode(root->right);
}

template<class T>
void insert(Node<T>*& r, const T& elem)
{
    if(r=nullptr)
    {
        Node<T>* newElem=new Node<T>(elem,nullptr,nullptr,1);
        re=newElem;
        return;
    }
    if(r->data<elem)
    {
        insert(r->right,elem);
        updateHeight(r->right);
        balanceRight(r->right);
    }
    else if(r->data>elem)
    {
        insert(r->left,elem);
        updateHeight(r->left);
        balanceLeft(r->left);
    }

}

template<class T>
bool remove(Node<T>*& tree, const T& elem)
{
    if(tree==nullptr)
    {
        return false;
    }
    if(r->data<elem)
    {
        remove(r->right,elem);
        updateHeight(r->right);
        balanceRight(r->right);
    }
    else if(r->data>elem)
    {
        remove(r->left,elem);
        updateHeight(r->left);
        balanceLeft(r->left);
    }
    else
    {
        if(!r->left && !r->right)
        {
            delete r;
            r=nullptr;
            return true;
        }
        else if(!r->left)
        {
            Node<T>* toDelete=r;
            r=r->right;
            delete toDelete;
        }
        else if(!r->right)
        {
            Node<T>* toDelete=r;
            r=r->left;
            delete toDelete;

        }
        else
        {
            r->data=findMinNode(r->right)->data;
            remove(r->right,r->data);
            updateHeight(r);
            balanceRight(r);

        }
    }
    return true;
}

int main()
{
    Node<int>* tree=new Node<int>(9,new Node<int>(6),new Node<int>(14,new Node<int>(12),new Node<int>(17,new Node<int>(20))));
    printTree(tree);
    free(tree);
}