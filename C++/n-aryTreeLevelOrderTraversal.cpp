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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root==NULL) return result;
        vector<int> cur;
        queue<Node*> curNodes;
        curNodes.push(root);
        int s; Node* temp;
        while (!curNodes.empty()){
            s = curNodes.size();
            for (int i=0; i<s; i++){
                temp = curNodes.front();
                curNodes.pop();
                cur.push_back(temp->val);
                if (!temp->children.empty()){
                    for (auto node : (temp->children)){
                        curNodes.push(node);   
                    }   
                }
            }
            result.push_back(cur);
            cur.clear();
        }
        return result;
    }
};