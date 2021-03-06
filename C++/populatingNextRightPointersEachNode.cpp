/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root==NULL) return NULL;
        Node* l = connect(root->left);
        Node* r = connect(root->right);
        while (l!=NULL){
            l->next = r;
            l=l->right;
            r=r->left;
        }
        return root;
    }
};