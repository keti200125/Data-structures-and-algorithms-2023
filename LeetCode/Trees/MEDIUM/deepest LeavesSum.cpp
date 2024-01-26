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
// 1302
class Solution {
public:

    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(q.empty())
            {
                return sum;
            }
            if(curr==nullptr)
            {
                sum=0;
                if(!q.empty())
                {
                    q.push(nullptr);
                }
            }
            else
            {
                sum+=curr->val;
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }

        }
        return sum;
    }
};