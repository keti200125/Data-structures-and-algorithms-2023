#include<iostream>
#include "treeUtils.h"

template<class T>
void inOrdredTraversel(const Tree<T>* t)
{
    if(t==nullptr)
    {
        return;
    }

    inOrdredTraversel(t->left);
    std::cout<<t->data<<" ";
    inOrdredTraversel(t->right);
}






int main()
{
     Tree<int> *tree = new Tree<int>(8, new Tree<int>(6, new Tree<int>(4)), new Tree<int>(12, new Tree<int>(10)));
    printTree(tree);
    inOrdredTraversel(tree);
    free(tree);
}