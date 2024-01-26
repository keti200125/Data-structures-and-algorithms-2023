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
 // think of better way
 // 110
class Solution {
public:
    int height(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }

        return 1+ max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
            return true;

        int balance=height(root->right)-height(root->left);

        if(balance!=-1&&balance!=0&&balance!=1)
            return false;

        if(!isBalanced(root->left)||!isBalanced(root->right))
            return false;

        return true;
    }
};