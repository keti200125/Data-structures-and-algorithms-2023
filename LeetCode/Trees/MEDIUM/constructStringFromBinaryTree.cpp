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
// 606
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root==nullptr)
        {
            return "";
        }
        string toReturn=to_string(root->val);
        string leftTree=tree2str(root->left);
        string rightTree=tree2str(root->right);
        if(rightTree=="" && leftTree=="") return toReturn;
        
        if(rightTree!="")
        {
           rightTree = "(" + rightTree + ")"; 
        }
        
        leftTree= "(" + leftTree + ")";
        
        return toReturn + leftTree + rightTree;
    }
};