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
    int maxDepth(Node* root) {
        if (!root) return 0;
        int maxd = 1;
        for (Node* n:root->children){
            if (!n) continue;
            maxd = max(maxd, maxDepth(n)+1);
        }
        return maxd;
    }
}; 