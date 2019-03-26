/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    
    vector<int> vals;
    int ind = 0;
    
    void populate(TreeNode* root){
        if (root==NULL) return;
        populate(root->left);
        vals.push_back(root->val);
        populate(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        populate(root);
    }
    
    /** @return the next smallest number */
    int next() {
        return vals[ind++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return ind<vals.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */