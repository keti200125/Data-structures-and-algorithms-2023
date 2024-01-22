#include<iostream>
#include "treeUtils.h"

int sum(const Tree<int>* t)
{
    if(!t)
    {
        return 0;

    }

    return t->data +sum(t->left) + sum(t->right);
}




int main()
{
     Tree<int> *tree = new Tree<int>(8, new Tree<int>(6, new Tree<int>(4)), new Tree<int>(12, new Tree<int>(10)));
    printTree(tree);
    std::cout<<sum(tree);
    free(tree);

}