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
// 501
class Solution {
public:
    void find(TreeNode* root,vector<int>& v,int& prev,int& meet,int& meetMax) {
        if(!root)
            return;

        find(root->left,v,prev,meet,meetMax);
        if(root->val==prev)
        {
            meet++; 
        }
        else
        {
            prev=root->val;
            meet=1;
        }
        if(meet>meetMax)
        {
            meetMax=meet;
            while(!v.empty())
            {
                v.pop_back();
            }
            v.push_back(root->val);
        }
        else if(meet==meetMax)
        {
            v.push_back(root->val);
        }
        prev=root->val;
        find(root->right,v,prev,meet,meetMax);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        int prev=INT_MAX;
        int meet=0;
        int meetMax=0;
        find(root,v,prev,meet,meetMax);
        return v;
    }
};