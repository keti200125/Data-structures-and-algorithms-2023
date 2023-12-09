#include <iostream>
#include "treeUtils.h"
#include <string>
#include <vector>

void findWords(Tree<char> *t, std::vector<std::string> &words, std::string &currWorld)
{
    if (!t)
    {
        return;
    }

    currWorld.push_back(t->data);

    if (!t->left && !t->right)
    {
        words.push_back(currWorld);
        currWorld.pop_back();
        return;
    }

    findWords(t->left, words, currWorld);
    findWords(t->right, words, currWorld);
    currWorld.pop_back();
}

void printWords(Tree<char> *tree)
{
    std::cout<<std::endl;
    std::string str = "";
    std::vector<std::string> vec;

    findWords(tree, vec, str);

    for (auto str : vec)
    {
        std::cout<<str<<std::endl;
    }
}

int main()
{
    Tree<char> *tree = new Tree<char>('C',
                                      new Tree<char>('A', new Tree<char>('T'), new Tree<char>('P')),
                                      new Tree<char>('E', new Tree<char>('O')));
    printTree(tree);
    printWords(tree);
    free(tree);
}