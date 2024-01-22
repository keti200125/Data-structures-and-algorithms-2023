#include<string.h>
#include<iostream>

template <class T>
struct AVLTree
{
    T data;
    AVLTree<T> *left;
    AVLTree<T> *right;
    int height;

    AVLTree(const T &elem, AVLTree<T> *l = nullptr, AVLTree<T> *r = nullptr,int h=1) : data{elem}, left{l}, right{r}, height{h} {}
};

template <class T>
void free(AVLTree<T> *t)
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
void printBT(const std::string &prefix, const AVLTree<T> *t, bool isLeft)
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
void printAVLTree(const AVLTree<T> *t)
{
    printBT("", t, false);
}