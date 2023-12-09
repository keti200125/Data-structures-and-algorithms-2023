#include<iostream>
#include "treeUtils.h"

int sumLeaves(Tree<int>* t)
{
    if(!t)
    {
        return 0;
    }

    if(!t->left && !t->right)
    {
        return t->data;
    }

    return sumLeaves(t->left)+sumLeaves(t->right);

}


int main()
{
    Tree<int> *tree = new Tree<int>(8, new Tree<int>(6, new Tree<int>(4)), new Tree<int>(12, new Tree<int>(10)));
    printTree(tree);
    std::cout<<std::endl;
    std::cout<<sumLeaves(tree);
    free(tree);

}