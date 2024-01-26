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
// 671
class Solution {
public:
    void findSecondMin(TreeNode* root,int &fst,int& snd,bool& isDifferent) {
        if(root==nullptr)
        {
            return;
        }
        if(root->val<fst ||fst==INT_MAX)
        {
            snd=fst;
            fst=root->val;
        }
        if(root->val!=fst && (root->val<snd || snd==INT_MAX))
        {
            snd=root->val;
            isDifferent =true;
        }

        findSecondMin(root->left,fst,snd,isDifferent);
        findSecondMin(root->right,fst,snd,isDifferent);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
            return -1;

        bool isDiff=false;   
        int fst=INT_MAX;
        int snd=INT_MAX;
        findSecondMin(root,fst,snd,isDiff);

        if(snd==INT_MAX && !isDiff)
            return -1;

        return snd;
    }
};