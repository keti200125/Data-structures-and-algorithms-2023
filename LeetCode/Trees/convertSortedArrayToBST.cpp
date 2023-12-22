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
//108
class Solution {
public:
    void makeBST(vector<int>& nums,TreeNode*& root) {
        int mid=nums.size()/2;

        if(nums.size()==0)
        {
            root=nullptr;
            return;
        }
        else if(nums.size()==1)
        {
            root=new TreeNode(nums[0]);
        }
        else
        {
            root=new TreeNode(nums[mid]);
        }
         vector<int> leftVec(nums.begin(),nums.begin()+mid);
         vector<int> rightVec(nums.begin() + mid+1,nums.end());

         makeBST(leftVec,root->left);
         makeBST(rightVec,root->right);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* tree=nullptr;
        makeBST(nums,tree);
        return tree;
    }
};