#include<iostream>
#include "treeUtils.h"
#include<vector>
#include<cmath>
//think


template<class T>
size_t height(Tree<T>* tree)
{
    if(!tree)
    {
        return -1;
    }

    return 1+std::max(height(tree->left),height(tree->right));
}

template<class T>
void word(Tree<T>* tree,int level)
{
    if(tree==nullptr)
    {
        return;
    }

    if(level==0)
    {
        std::cout<<tree->data<<" ";
    }
    else
    {
        word(tree->left,level-1);
        word(tree->right,level-1);
    }

}



void findWords(Tree<char>* tree)
{
    int h=height(tree)+1;

    for(int i=0;i<h;i++)
    {
        word(tree,i);
        std::cout<<std::endl;
    }

}

int  main()
{
    Tree<char> *tree = new Tree<char>('A',
     new Tree<char>('A', new Tree<char>('C'),new Tree<char>('A')), 
     new Tree<char>('M', new Tree<char>('T')));
    printTree(tree);
    findWords(tree);
    free(tree);
}