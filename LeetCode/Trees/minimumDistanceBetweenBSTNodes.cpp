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
// 783
class Solution {
public:
    void minDiff(TreeNode* root,int& mini,int& last) {
        if(root==nullptr)
            return;

        minDiff(root->left,mini,last);
        mini=min(mini,abs(last-root->val));
        last=root->val;
        minDiff(root->right,mini,last);
        
    }
    int minDiffInBST(TreeNode* root) {
        int min=INT_MAX;
        int last=INT_MAX;
        minDiff(root,min,last);
        return min;
    }
};