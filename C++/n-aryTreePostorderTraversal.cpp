/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    
    vector<int> res;
    
    vector<int> postorder(Node* root) {
        traverse(root);
        return res;
    }
    
    void traverse(Node* root){
        if (!root) return;
        for (Node* c:root->children){
            traverse(c);
        }
        res.push_back(root->val);
    }
};