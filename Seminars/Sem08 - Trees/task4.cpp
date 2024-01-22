#include <iostream>
#include "treeUtils.h"
#include <vector>
#include<string>


std::string decoding(const Tree<char>* t,const std::string& str)
{
    std::string res;
    const Tree<char>* head=t;

    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='0')
        {
            t=t->left;
        }
        if(str[i]=='1')
        {
            t=t->right;
        }

        if(!t->left && !t->right)
        {
            res.push_back(t->data);
            t=head;
        }
    }
    return res;
}



int main()
{
    Tree<char> *tree = new Tree<char>('X', new Tree<char>('X', 
    new Tree<char>('B'),new Tree<char>('C')), new Tree<char>('A'));
    printTree(tree);
    std::cout<<decoding(tree,"1001011");

    free(tree);
}