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
//think for better, Keti
//589

class Solution {
public:
    void preorderHelp(Node* root,vector<int>& v) {      

        if(root==nullptr)
        {
            return;
        } 
        v.push_back(root->val);
        //for(int i=0;i<(root->children).size();i++){
        for(auto el:root->children)
        {
            preorderHelp(el,v);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> v;
        preorderHelp(root,v);
        return v;
    }
};