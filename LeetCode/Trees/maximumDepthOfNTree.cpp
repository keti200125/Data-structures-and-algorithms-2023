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
//559
class Solution {
public:
    int maxDepth(Node* root) {
        if(root==nullptr)
        {
            return 0;
        }

        int max = 0;

        for(Node* i: root->children)
        {
            max = std::max(max, maxDepth(i));
        }
        return max + 1;
    }
};