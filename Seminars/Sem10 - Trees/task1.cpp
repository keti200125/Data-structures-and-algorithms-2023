#include<iostream>
#include "treeUtils.h"
#include<vector>


template<class T>
struct Node
{
    T data;
    std::vector<Node *> children;

    Node(const T& elem):data{elem} {}
};





int main()
{

}