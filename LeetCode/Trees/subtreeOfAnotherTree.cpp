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
// 572
class Solution {
public:
    bool isSub(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr &&root==nullptr)
            return true;
        if(root==nullptr||subRoot==nullptr)
            return false;

        if(root->val==subRoot->val)
        { 
            return isSub(root->left,subRoot->left)
            &&isSub(root->right,subRoot->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr)
            return false;

        if(root->val==subRoot->val)
        {
            return isSub(root,subRoot)
            || isSubtree(root->left,subRoot)
            || isSubtree(root->right,subRoot);
        }
        
        return isSubtree(root->left,subRoot)
            || isSubtree(root->right,subRoot);

       

    }
};