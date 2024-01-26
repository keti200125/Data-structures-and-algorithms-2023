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
// 530
class Solution {
public:
    void getMin(TreeNode* root,int& mini,int& last,bool& isFirst) {
        if(root==nullptr)
            return;
            
        getMin(root->left,mini,last,isFirst);
        if(isFirst)
        {
            isFirst=false;
            last=root->val;
        }
        else
        {
            int curr=abs(root->val-last);
            mini=min(curr,mini);
            last=root->val;
        }
        getMin(root->right,mini,last,isFirst);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        bool isFirst=1;
        int last;
        getMin(root,mini,last,isFirst);
        return mini;


    }
};