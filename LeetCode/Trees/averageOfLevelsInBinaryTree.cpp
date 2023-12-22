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
//637
class Solution {
public:
    void average(TreeNode* root,queue<TreeNode*>& q,vector<double>& v) {
        double sum=0;
        int nums=0;
        q.push(root);
        q.push(nullptr);

        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr==nullptr)
            {
                if(nums!=0)
                {
                double average=sum/nums;
                v.push_back(average);
                q.push(nullptr);
                sum=0;
                nums=0;
                }  
            }
            else
            {
                sum+=curr->val;
                ++nums;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
    }

    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> v;
        average(root,q,v);
        return v;
    }
};