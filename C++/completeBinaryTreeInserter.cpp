/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    
    TreeNode* tree;
    vector<TreeNode*> nodes;
    
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* temp;
        q.push(root);
        while (!q.empty()){
            temp = q.front();
            nodes.push_back(temp);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
            q.pop();
        }
        tree = root;
    }
    
    int insert(int v) {
        int ind = (nodes.size()-1)/2;
        TreeNode* node = new TreeNode(v);
        if ((nodes.size()-1)%2==0){
            nodes[ind]->left = node;
        }else{
            nodes[ind]->right = node;
        }
        nodes.push_back(node);
        return nodes[ind]->val;
    }
    
    TreeNode* get_root() {
        return tree;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */