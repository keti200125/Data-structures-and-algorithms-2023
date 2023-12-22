/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// 590
class Solution {
public:
    void postorderHelp(Node* root,vector<int>& v)
    {
        if(root==nullptr)
        {
            return;
        }
        for(auto i:root->children)
        {
            postorderHelp(i,v);
        }
        v.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> v;
        postorderHelp(root,v);
        return v;
    }
};