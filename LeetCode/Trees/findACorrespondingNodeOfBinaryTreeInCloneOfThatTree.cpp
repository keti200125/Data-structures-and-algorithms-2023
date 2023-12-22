/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//1379
class Solution {
public:
    TreeNode* getTarget(TreeNode*& toReturn, TreeNode* cloned, TreeNode* target) {
        if(cloned==nullptr)
        {
            return cloned;
        }

        if(cloned->val==target->val)
        {
            toReturn=cloned;
        }
        getTarget(toReturn,cloned->left,target);
        getTarget(toReturn,cloned->right,target);

        return toReturn;
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* t=nullptr;
       return getTarget(t,cloned,target);
    }
};