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
// 257
class Solution {
public:
    void binaryPaths(TreeNode* root,vector<string>& v,vector<int>& nums) {
        if(root==nullptr)
            return;

        nums.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr)
        {
            string str;
            for(auto i:nums)
            {
                str.append(to_string(i)+"->");
            }
            str.pop_back();
            str.pop_back();
            v.push_back(str);
        }

        binaryPaths(root->left,v,nums);
        binaryPaths(root->right,v,nums);
        nums.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        vector<int> nums;
        binaryPaths(root,v,nums);
        return v;
    }
};