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
// 404
class Solution {
public:
      int sumOfLeft(TreeNode* root,bool isRight) {
        if(root==nullptr)
            return 0;

        if(root->left==nullptr && root->right==nullptr&&!isRight)
            return root->val;

        int left=sumOfLeft(root->left,false);
        int right=sumOfLeft(root->right,true);

        return left + right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        bool isRight=true;
        return sumOfLeft(root,isRight);
    }
};