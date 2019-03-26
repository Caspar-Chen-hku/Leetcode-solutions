/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==NULL) return NULL;
        Node* cur = head;
        Node* temp;
        while (cur!=NULL){
            temp = new Node(cur->val);
            temp->next=cur->next;
            cur->next=temp;
            cur= temp->next;
        }
        cur = head;
        while (cur!=NULL){
            temp = cur->random;
            if (temp==NULL){
                cur->next->random = NULL;
            }else{
                cur->next->random = temp->next;                
            }
            cur=cur->next->next;
        }
        Node* nhead = head->next;
        head->next = nhead->next;
        cur = nhead->next;
        Node* ncur = nhead;
        while (cur!=NULL){
            ncur->next = cur->next;
            cur->next = cur->next->next;
            cur=cur->next;
            ncur = ncur->next;
        }
        return nhead;
    }
};