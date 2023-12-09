#include<string.h>
#include<iostream>

template <class T>
struct Tree
{
    T data;
    Tree<T> *left;
    Tree<T> *right;

    Tree(const T &elem, Tree<T> *l = nullptr, Tree<T> *r = nullptr) : data{elem}, left{l}, right{r} {}
};

template <class T>
void free(Tree<T> *t)
{
    if (t == nullptr)
    {
        return;
    }
    free(t->left);
    free(t->right);
    delete t;
}


template <class T>
void printBT(const std::string &prefix, const Tree<T> *t, bool isLeft)
{
    if (t != nullptr)
    {
        std::cout << prefix;

       std::cout << (isLeft ? "|--" : "L--");
        std::cout << t->data << std::endl;

        printBT(prefix + (isLeft ? "|   " : "    "), t->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), t->right, false);
    }
}

template <class T>
void printTree(const Tree<T> *t)
{
    printBT("", t, false);
}