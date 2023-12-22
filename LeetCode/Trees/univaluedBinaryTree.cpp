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
//965
class Solution {
public:
    bool isUnival(TreeNode* root,int value) {
        if(root==nullptr)
        {
            return true;
        }
        if(root->val!=value)
        {
            return false;
        }
        return isUnival(root->left,value) &&isUnival(root->right,value);
    }
    bool isUnivalTree(TreeNode* root) {
        return isUnival(root,root->val);

    }
};