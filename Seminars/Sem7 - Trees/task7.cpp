#include<iostream>
#include "treeUtils.h"


template<class T>
size_t elementsCount(const Tree<T>* tree)
{
    if(!tree)
    {
        return 0;
    }

    return 1+ elementsCount(tree->left) + elementsCount(tree->right);
}



int main()
{
    
     Tree<int> *tree = new Tree<int>(8, new Tree<int>(6, new Tree<int>(4)), new Tree<int>(12, new Tree<int>(10)));
    printTree(tree);
    std::cout<<elementsCount(tree);
    free(tree);
    
}