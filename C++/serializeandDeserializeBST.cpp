/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        else{
            string result = to_string(root->val);
            string temp1 = serialize(root->left);
            return result + "," + to_string(temp1.length()) + "," + temp1 +
                  "," + serialize(root->right);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        int ind = data.find(",");
        TreeNode* root = new TreeNode(stoi(data.substr(0,ind)));
        int ind2 = data.find(",",ind+1);
        int len = stoi(data.substr(ind+1,ind2-ind-1));
        root->left = deserialize(data.substr(ind2+1,len));
        root->right = deserialize(data.substr(ind2+2+len));
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));