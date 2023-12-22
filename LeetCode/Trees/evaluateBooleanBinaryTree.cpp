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
//2331
class Solution {
public:
    bool evaluate(int op,int first,int second)
    {
        if(op==2)
        {
            return first||second;
        }
        return first&&second;
    }

    
    bool evaluateTree(TreeNode* root) {
        if(root->val==1)
            return true;

        if(root->val==0)
            return false;

        if(root->val==2)
        {
        return evaluateTree(root->left) || evaluateTree(root->right);
        }
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
};