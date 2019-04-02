/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        while (cur && !cur->child){
            cur = cur->next;
        }
        if (!cur) return head;
        Node* c = cur->child;
        Node* tail = c;
        while (tail->next){
            tail = tail->next;
        }
        tail->next = cur->next;
        if (cur->next) cur->next->prev = tail;
        c->prev = cur;
        cur->next = c;
        cur->child = NULL;
        c = flatten(c);
        return head;
    }
};