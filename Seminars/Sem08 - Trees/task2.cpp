#include <iostream>
#include "treeUtils.h"
#include <vector>

template <class T>
bool isBSTHelp(Tree<T> *t, T &elem, bool &hasLast)
{
    if (t != nullptr)
    {
        isBSTHelp(t->left, elem, hasLast);
        if (!hasLast)
        {
            hasLast = true;
            elem = t->data;
        }
        if (elem > t->data)
        {
            return false;
        }

        isBSTHelp(t->right, elem, hasLast);
    }

    return true;
}

template <class T>
bool isBST(Tree<T> *t)
{
    T elem;
    bool hasLast = false;
    return isBSTHelp(t, elem, hasLast);
}

int nodes(Tree<int>* t,int& value)
{
    if(t==nullptr)
    {
        return 0;
    }

    value++;
    return t->data+ nodes(t->left,value) + nodes(t->right,value);
}

int averageOfSubtree(Tree<int>* root) {
        if(root==nullptr)
        {
            return 0;
        } 

        int elems= 0;
        int sumElements=nodes(root,elems) - root->data;
        elems=elems-1;
        if(elems==0)
        {
            return 0;
        }
        
        
        if((sumElements/elems) != root->data)
        {
           return averageOfSubtree(root->left) + averageOfSubtree(root->right);
        }    
        return 1 + averageOfSubtree(root->left) + averageOfSubtree(root->right);

    }

int main()
{
    Tree<int> *tree = new Tree<int>(14, new Tree<int>(28, new Tree<int>(0)), new Tree<int>(14, new Tree<int>(14)));
    Tree<int> *tree1 = new Tree<int>(8, new Tree<int>(6, new Tree<int>(4)), new Tree<int>(12, new Tree<int>(10)));
    Tree<int> *tree2 = new Tree<int>(8, new Tree<int>(6, new Tree<int>(20)), new Tree<int>(12, new Tree<int>(10)));
    printTree(tree);
   // std::cout << std::endl;
   // std::cout << isBST(tree2);
   int value=0;
   std::cout<<nodes(tree,value)<<" ";
   std::cout<<value<<std::endl;
   std::cout<<averageOfSubtree(tree);
    free(tree);
    free(tree2);
}
