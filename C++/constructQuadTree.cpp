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
    Node* construct(vector<vector<int>>& grid) {
        return toConst(grid, 0, 0, grid.size()-1, grid[0].size()-1);
    }
    
    Node* toConst(vector<vector<int>>& grid, int x1, int y1, int x2, int y2){
        if (x1==x2){
            return new Node(grid[x1][y1]==1, true, NULL, NULL, NULL, NULL);
        }else{
            int xmid = (x1+x2)/2, ymid = (y1+y2)/2;
            Node* res = new Node();
            res->topLeft = toConst(grid, x1, y1, xmid, ymid);
            res->topRight = toConst(grid, x1, ymid+1, xmid, y2);
            res->bottomLeft = toConst(grid, xmid+1, y1, x2, ymid);
            res->bottomRight = toConst(grid, xmid+1, ymid+1, x2, y2);
            res->val = grid[x1][y1]==1;
            res->isLeaf = false;
            if (res->topLeft->isLeaf && res->topRight->isLeaf
                && res->bottomLeft->isLeaf && res->bottomRight->isLeaf &&
                res->topLeft->val == res->topRight->val &&
               res->topLeft->val == res->bottomLeft->val &&
               res->topLeft->val == res->bottomRight->val){
                res->isLeaf = true;
                res->topLeft = NULL;
                res->topRight = NULL;
                res->bottomLeft = NULL;
                res->bottomRight = NULL;
            }
            return res;
        }
    }
};