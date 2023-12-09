#include<iostream>
#include "treeUtils.h"

template<class T>
int height(const Tree<T>* t) 
{
    if(t==nullptr)
    {
        return -1;
    }

    return  1 + std::max(height(t->left),height(t->right));
}



int main()
{
     Tree<int> *tree = new Tree<int>(8, new Tree<int>(6, new Tree<int>(4)), new Tree<int>(12, new Tree<int>(10)));
    printTree(tree);
    std::cout <<height(tree);
    free(tree);

}