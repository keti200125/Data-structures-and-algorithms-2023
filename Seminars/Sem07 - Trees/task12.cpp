#include<iostream>
#include "treeUtils.h"


template<class T>
void mirror(Tree<T>*& t)
{
    if(!t)
    {
        return;

    }

    Tree<T>* left=t->left;
    t->left=t->right;
    t->right=left;

    mirror(t->left);
    mirror(t->right);

}


int main()
{
    Tree<char> *tree = new Tree<char>('C',
                                      new Tree<char>('A', new Tree<char>('T'), new Tree<char>('P')),
                                      new Tree<char>('E', new Tree<char>('O')));
    printTree(tree);
    mirror(tree);
    std::cout<<std::endl;
    printTree(tree);
    free(tree);


}


