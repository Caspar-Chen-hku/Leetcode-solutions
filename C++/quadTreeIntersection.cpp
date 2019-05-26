/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree2->isLeaf && !(quadTree1->isLeaf)){
            return intersect(quadTree2, quadTree1);
        }else if (quadTree1->isLeaf){
            if (quadTree1->val){
                return quadTree1;
            }else{
                return quadTree2;
            }
        }else{
            Node* newnode = new Node;
            newnode->isLeaf = false;
            newnode->topLeft = 
                intersect(quadTree1->topLeft, quadTree2->topLeft);
            newnode->topRight = 
                intersect(quadTree1->topRight, quadTree2->topRight);
            newnode->bottomLeft = 
                intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            newnode->bottomRight = 
                intersect(quadTree1->bottomRight, quadTree2->bottomRight);
            newnode->val = false;
            bool oneval = newnode->topLeft->val;
            if (newnode->topRight->isLeaf &&
                newnode->topRight->val == oneval && 
                newnode->bottomLeft->isLeaf  &&
               newnode->bottomLeft->val == oneval &&
                 newnode->bottomRight->isLeaf  &&
               newnode->bottomRight->val == oneval){
                newnode = new Node(oneval, true, NULL, NULL, NULL, NULL);
            }
            return newnode;
        }
    }
};