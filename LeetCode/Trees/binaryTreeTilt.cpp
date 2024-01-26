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
// 563
 // i think there is better way with one recursion
 // Keti, try when you have time
class Solution {
public:
int subSum(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        return root->val+subSum(root->left) + subSum(root->right); 
    }
    int findTilt(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int left=subSum(root->left);
        int right=subSum(root->right);
        return abs(left-right)+ findTilt(root->left) + findTilt(root->right);

    }
    
};