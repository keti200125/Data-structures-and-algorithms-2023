#include <iostream>
#include "treeUtils.h"

template <class T>
bool contains(Tree<T> *tree, const T &elem)
{
    if (tree == nullptr)
    {
        return false;
    }

    if (tree->data = elem)
    {
        return true;
    }

    return contains(tree->left, elem) || contains(tree->right, elem);
}

template <class T>
bool containsBST(Tree<T> *tree, const T &elem)
{
    if (tree == nullptr)
    {
        return false;
    }

    if (tree->data == elem)
    {
        return true;
    }

    if (tree->data > elem)
    {
        return containsBST(tree->left, elem);
    }

    return containsBST(tree->right, elem);
}

int main()
{
    Tree<int> *tree = new Tree<int>(10, new Tree<int>(6, new Tree<int>(4)), new Tree<int>(12, new Tree<int>(8)));
    printTree(tree);
    std::cout << containsBST(tree, 2);
    free(tree);
}