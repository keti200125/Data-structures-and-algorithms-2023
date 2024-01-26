/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 2265
class Solution {
public:
//There is better solution if we start from the leaves, do it later Keti :)

    int sum(TreeNode* root, int& value)
    {
        if(root==nullptr)
        {
            return 0;
        }

        value++;
        return root->val+sum(root->left,value)+sum(root->right,value);

    }
    
    int averageOfSubtree(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        } 

        int elems= 0;
        int sumElements=sum(root,elems);
        if(elems==0)
        {
            return 0;
        }
        if((sumElements/elems) != root->val)
        {
            return averageOfSubtree(root->left) + averageOfSubtree(root->right);
        }     

        return 1 + averageOfSubtree(root->left) + averageOfSubtree(root->right);
    }
};