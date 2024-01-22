#include <iostream>
#include "treeUtils.h"
#include <queue>

//Keti, think of better solution without the last "_...."

void print(const Tree<char> *tree)
{
    if (tree == nullptr)
    {
        return;
    }
    std::queue<const Tree<char> *> q;
    q.push(tree);

    while (!q.empty())
    {
        int levelLen = q.size();
        for (int i = 0; i < levelLen; i++)
        {
            const Tree<char> *curr = q.front();
            q.pop();
            if (curr == nullptr)
            {
                std::cout << "_";
            }
            else
            {
                std::cout << curr->data;

                if (curr->left)
                    q.push(curr->left);
                else
                    q.push(nullptr);
                if (curr->right)
                    q.push(curr->right);
                else
                    q.push(nullptr);
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    Tree<char> *tree = new Tree<char>('I',
                                      new Tree<char>('a', new Tree<char>('g', new Tree<char>('a', new Tree<char>('n', new Tree<char>('s'), nullptr), new Tree<char>('g', nullptr, new Tree<char>('!'))), new Tree<char>('t', nullptr, new Tree<char>('p'))),
                                                     new Tree<char>('o', nullptr,
                                                                    new Tree<char>('s', new Tree<char>('r'), new Tree<char>('o')))),
                                      new Tree<char>('m', new Tree<char>('o', new Tree<char>('o', new Tree<char>('b'), new Tree<char>('l')), new Tree<char>('l', new Tree<char>('e'), new Tree<char>('m'))),
                                                     new Tree<char>('d', new Tree<char>('v'), new Tree<char>('i'))));
    print(tree);
    free(tree);
}