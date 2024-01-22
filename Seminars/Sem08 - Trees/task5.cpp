#include <iostream>
#include "treeUtils.h"
#include <vector>
#include <string>

template <class T>
size_t countElems(Tree<T> *t, const T &min, const T &max)
{
    if (t == nullptr)
        return 0;

    if (t->data < min)
        return countElems(t->right, min, max);

    if (t->data > max)
        return countElems(t->left, min, max);

    return 1 + countElems(t->left, min, max) + countElems(t->right, min, max);
}

template <class T>
T sumElems(Tree<T> *t, const T &min, const T &max)
{
    if (t == nullptr)
    {
        return 0;
    }

    size_t el = countElems(t->left, min, max) + countElems(t->right, min, max);

    if (el % 2 == 1)
    {
        return t->data + sumElems(t->left, min, max) + sumElems(t->right, min, max);
    }

    return sumElems(t->left, min, max) + sumElems(t->right, min, max);
}

/*

// O(n)
template <class T>
void solution(Tree<T> *t, const T &min, const T &max, int &nums, T &sum)
{
    if (t == nullptr)
        return;

    if (t->data < min)
    {
        solution(t->right, min, max, nums, sum);
        if(nums%2==1)
        {
            sum=sum+t->data;
        }
        return;
    }

    if (t->data > max)
    {
        solution(t->left, min, max, nums, sum);
         if(nums%2==1)
        {
            sum=sum+t->data;
        }
        return;
    }

    solution(t->left, min, max, nums, sum);
    solution(t->right, min, max, nums, sum);


    if (nums % 2 == 1)
    {
        sum = sum + t->data;
    }
   nums++;
}

template <class T>
T solve(Tree<T> *t, const T &min, const T &max)
{
    T nums = T();
    T sum = T();
    solution(t, min, max, nums, sum);
    return sum;
}

*/


int main()
{
    Tree<int> *tree = new Tree<int>(8, new Tree<int>(6, new Tree<int>(4)), new Tree<int>(12, new Tree<int>(10)));
    printTree(tree);
    std::cout << std::endl;
    //std::cout << solve(tree, 6, 11);
     std::cout << std::endl;
     print(tree);
    //std::cout << sumElems(tree, 6, 11);
    free(tree);
}