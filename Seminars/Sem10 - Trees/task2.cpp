#include<iostream>
#include<vector>
#include<queue>
#include "treeUtils.h"


void printL(const Tree<int>* tree,std::vector<const Tree<int>*>& v)
{
    std::queue<const Tree<int>*> q;
    q.push(tree);
    q.push(nullptr);
    int i=0;

    while(!q.empty())
    {
        const Tree<int>* curr=q.front();
        q.pop();

        if(curr==nullptr)
        {
            v.push_back(nullptr);
            if(!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            v.push_back(curr);
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }

        }
    }
}

void printLevels(const Tree<int>* tree)
{
    std::vector<const Tree<int>*> v;
    printL(tree,v);
    for(auto elem:v)
    {
        if(elem==nullptr)
        {
            std::cout<<std::endl;
        }
        else
        {
            std::cout<<elem->data<<" ";
        }

    }

}

template <class T>
void print(const Tree<T>* root)
{
	if (root == nullptr)
		return;

	std::queue<const Tree<T>*> q;
	q.push(root);

	while (!q.empty())
	{
		size_t currLevel = q.size();

		for (size_t i = 0; i < currLevel; i++)
		{
			const Tree<T>* curr = q.front();
			q.pop();

			std::cout << curr->data << " ";

			if (curr->left != nullptr)
				q.push(curr->left);

			if (curr->right != nullptr)
				q.push(curr->right);
		}

		std::cout << std::endl;
	}
}



int main()
{
    Tree<int>* tree=new Tree<int>(3,new Tree<int>(9),new Tree<int>(20,new Tree<int>(15),new Tree<int>(7)));
    printTree(tree);
    printLevels(tree);
    free(tree);
}