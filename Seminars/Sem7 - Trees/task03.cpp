#include "treeUtils.h"
#include <iostream>
// #include<algorithm>
#include <cmath>

template <class T>
int maxEl(Tree<T> *tree)
{
    if (tree == nullptr)
    {
        return INT_MIN;
    }

    return std::max(tree->data, std::max(
                                    maxEl(tree->left), maxEl(tree->right)));
}

template <class T>
const T &maxBST(Tree<T> *tree)
{
    while (tree->right != nullptr)
    {
        tree = tree->right;
    }

    return tree->data;
}

template <class T>
const T &minBST(Tree<T> *tree)
{
    while (tree->left != nullptr)
    {
        tree = tree->left;
    }

    return tree->data;
}

template <class T>
T minEl(Tree<T> *tree)
{
    T res = tree->data;

    if (tree->left != nullptr)
    {
        res = std::min(res, minEl(tree->left));
    }
    if (tree->right != nullptr)
    {
        res = std::min(res, minEl(tree->right));
    }

    return res;
}

int main()
{
    Tree<int> *tree = new Tree<int>(8, new Tree<int>(6, new Tree<int>(4)), new Tree<int>(12, new Tree<int>(10)));
    printTree(tree);
    std::cout << minEl(tree);
    free(tree);
}