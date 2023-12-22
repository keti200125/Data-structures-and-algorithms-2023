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
//897
class Solution {
public:
    void increasing(TreeNode* root,TreeNode*& newTree,TreeNode*& start) {
        if(root==nullptr)
        {
            return;
        }

        increasing(root->left,newTree,start);
        if(!newTree)
        {
            newTree=new TreeNode(root->val);
            start=newTree;
        }
        else
        {
            newTree->right=new TreeNode(root->val);
            newTree=newTree->right;
        }
        increasing(root->right,newTree,start);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==nullptr)
        {
            return nullptr;
        }
        TreeNode* newTree=nullptr;
        TreeNode* start;
        increasing(root,newTree,start);
        return start;
    }
};