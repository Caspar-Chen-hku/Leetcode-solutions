/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
      build_graph(nullptr, root); 
      vector<int> ans;
      
      queue<TreeNode*> q;
      q.push(target);
      int step = 0;
      while(!q.empty())
      {
        int size = q.size();
        while(size--)
        {
          TreeNode* curr = q.front();
          q.pop();
          m_seen.insert(curr);
          if(step == k) ans.push_back(curr->val);
          
          for(TreeNode* next : m_graph[curr])
          {
            if(m_seen.count(next)) continue;
            q.push(next);
          }
        }
        if(++step > k) break;
      }
      
      return ans;
    }
  
private:
    void build_graph(TreeNode* parent, TreeNode* curr)
    {
        if(!curr) return;
        if(parent)
        {
          m_graph[parent].push_back(curr);
          m_graph[curr].push_back(parent);
        }
        build_graph(curr, curr->left);
        build_graph(curr, curr->right);
    }
  
    unordered_map<TreeNode*, vector<TreeNode*>> m_graph;
    unordered_set<TreeNode*> m_seen;
};