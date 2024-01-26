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
// 101
class Solution {
public:

    bool isSame(TreeNode* root1,TreeNode* root2)
    {
        if(!root1 && !root2)
        {
            return true;
        }
        if((!root1) || (!root2) || (root1->val!=root2->val))
        {
            return false;
        }

        return isSame(root1->left,root2->right) && isSame(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
        {
            return 1;
        }

        return isSame(root->left,root->right);
        
    }
};