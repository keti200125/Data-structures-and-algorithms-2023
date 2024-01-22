#include <iostream>
#include "treeUtils.h"
#include <vector>

template<class T>
bool sameTrees(Tree<T>* first, Tree<T>* second)
{
    if(!first && !second)
        return true;

    if(first && second)
    {
        return first->data==second->data 
        && sameTrees(first->left,second->left) 
        && sameTrees(first->right,second->right);
    }

    return false;
}


int main()
{
    Tree<int> *tree = new Tree<int>(8, new Tree<int>(6, new Tree<int>(4)), new Tree<int>(12, new Tree<int>(10)));
    Tree<int> *tree2 = new Tree<int>(8, new Tree<int>(6, new Tree<int>(20)), new Tree<int>(12, new Tree<int>(10)));
    std::cout << std::endl;
    std::cout <<sameTrees(tree,tree);
    free(tree);
    free(tree2);
}
