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
        queue<Node*> cur;
        int temp;
        cur.push(root);
        Node* target;
        while(!cur.empty()){
            temp = cur.size();
            for (int i=0; i<temp; i++){
                target=cur.front();
                cur.pop();
                if (i<temp-1){
                    target->next=cur.front();
                }
                if (target->left) cur.push(target->left);
                if (target->right) cur.push(target->right);
            }
        }
        return root;
    }
};