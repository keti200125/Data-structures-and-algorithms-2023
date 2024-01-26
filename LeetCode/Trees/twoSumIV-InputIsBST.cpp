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

//653

 //There is better solution, with less complexity
 //Keti, think when you have time
class Solution {
public:
        bool findArr(TreeNode* root, int k,vector<int>& v) {
        if(root==nullptr)
        {
            return false;
        }
        for(int i=0;i<v.size();i++)
        {
            if((v[i]+root->val)==k)
            {
                return true;
            }
        }
        v.push_back(root->val);
        return  findArr(root->left,k,v) || findArr(root->right,k,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        return findArr(root,k,v);
    }
};