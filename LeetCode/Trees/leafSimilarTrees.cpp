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
//872
class Solution {
public:
    void leaves(TreeNode* root,vector<int>& v)
    {
        if(!root)
            return;

        if(!root->left && !root->right)
            v.push_back(root->val);

        leaves(root->left,v);
        leaves(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        leaves(root1,v1);
        leaves(root2,v2);
        if(v1.size()==v2.size())
        {
            for(int i=0;i<v1.size();i++)
            {
                if(v1[i]!=v2[i])
                    return false;
            }
            return true;
        }
        return false;
    }
};