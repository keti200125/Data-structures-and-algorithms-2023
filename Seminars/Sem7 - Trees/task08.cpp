#include <iostream>
#include "treeUtils.h"
#include <vector>

//think

template<class T>
size_t elementsCount(const Tree<T>* tree)
{
    if(!tree)
    {
        return 0;
    }

    return 1+ elementsCount(tree->left) + elementsCount(tree->right);
}


bool numbersAreInTree(Tree<int> *tree,int n, std::vector<bool> &nums)
{
    if (!tree)
    {
        return true;
    }

    if ((tree->data < 1 || tree->data > n) || nums[tree->data - 1])
    {
        return false;
    }

    nums[tree->data - 1] = true;

    return (numbersAreInTree(tree->left,n, nums) && numbersAreInTree(tree->right,n, nums));
}

bool numbersAreIn(Tree<int> *tree, int n)
{
    std::vector<bool> nums;
    for (int i = 0; i < n; i++)
    {
        nums.push_back(false);
    }

    if(elementsCount(tree)<n)
    {
        return false;
    }

    bool in=numbersAreInTree(tree,n, nums);

    return in;
}

int main()
{
    Tree<int> *tree = new Tree<int>(1, new Tree<int>(2, new Tree<int>(3)));
    printTree(tree);
    std::cout << numbersAreIn(tree, 3);
    free(tree);



    
}