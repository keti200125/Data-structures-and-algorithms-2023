#include <iostream>
#include <string>
#include "treeUtils.h"



template<class T>
void addElemBST(Tree<T>*& t,const T& elem)
{
    if(t==nullptr)
    {
        t=new Tree<T>(elem);
        return;

    }
    else if(t->data<elem)
    {
        addElemBST(t->left,elem);
    }
    else if(t->data>elem)
    {
        addElemBST(t->right,elem);
    }


}

int main()
{
    Tree<int> *tree = new Tree<int>(0, new Tree<int>(1), new Tree<int>(2));
    addElemBST(tree,5);
   printTree(tree);
    free(tree);
};