#include<iostream>
#include "treeUtils.h"
#include<vector>


template<class T>
void sortVec(Tree<T>* t, std::vector<T>& vec)
{
    if(t)
    {
        sortVec(t->left,vec);
        vec.push_back(t->data);
        sortVec(t->right,vec);
    }
}

template<class T>
std::vector<T> sortedVec(Tree<T>* t)
{
    std::vector<T> v;
    sortVec(t,v);
    return v;
}


int main()
{
       Tree<int> *tree = new Tree<int>(8, new Tree<int>(6, new Tree<int>(4)), new Tree<int>(12, new Tree<int>(10)));
    printTree(tree);
    std::vector<int> v;
    v=sortedVec(tree);
    std::cout<<std::endl;
    for(int i=0;i<v.size();i++)
    {
        std::cout<<v[i]<<" ";
    }


    free(tree);

}
