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
//1022
class Solution {
public:

    void find(TreeNode* root,std::vector<int>& v,std::vector<int>& nums)
    {
        if(!root)
        {
            return;
        }
        nums.push_back(root->val);

        if(!root->left && !root->right)
        {
            int num=nums[0];
            for(int i=1;i<nums.size();i++)
            {
                num=2*num;
         wert       if(nums[i]==1)
                {
                    num=num+1;
                }
            }
            v.push_back(num);
            nums.pop_back();
            return;
        }
        find(root->left,v,nums);
        find(root->right,v,nums);
        nums.pop_back();

    }
    int sumRootToLeaf(TreeNode* root) {
        std::vector<int> v;
        std::vector<int> nums;
        find(root,v,nums);
        int sum=0;

        for(auto elem: v)
        {
            sum+=elem;
        }

        return sum;
    }
};