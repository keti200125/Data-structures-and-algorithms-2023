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
//94
class Solution {
public:

    void inorderTraversalHelp(TreeNode* root,vector<int>& v) {
        
        if(root==nullptr)
        {
            return;
        }
        inorderTraversalHelp(root->left,v);
        v.push_back(root->val);
        inorderTraversalHelp(root->right,v);
    }

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> v;
        inorderTraversalHelp(root,v);
        return v;

    }
};