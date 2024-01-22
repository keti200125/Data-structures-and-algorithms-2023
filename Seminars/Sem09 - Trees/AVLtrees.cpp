#include<iostream>
#include "treeUtils.h"

// Баланс фактор на възел k определяме като: bf(k) = h(k->right) - h(k->left). 
//Целта ни е за всеки възел k bf(k) да е в множеството {-1, 0, 1}.

//int height(AVLTree<int>)

int main()
{
     AVLTree<int> *tree = new AVLTree<int>(1, new AVLTree<int>(2, new AVLTree<int>(3)),new AVLTree<int>(5));
     printAVLTree(tree);
     std::cout<<std::endl;
     std::cout<<tree->height<<std::endl;

     free(tree);

}