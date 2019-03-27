class TrieNode {
    public:
    TrieNode* children[26];
    bool isLeaf;
    
    TrieNode(){
        for (int i=0; i<26; i++){
            children[i] = NULL;
        }
        isLeaf = false;
    }
};

class Trie {
public:
    
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for (int i=0; i<word.length(); i++){
            int temp = word[i]-'a';
            if (p->children[temp]==NULL){
                p->children[temp] = new TrieNode;
            }
            p = p->children[temp];
        }
        p->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for (int i=0; i<word.length(); i++){
            int temp = word[i]-'a';
            if (p->children[temp]==NULL){
                return false;
            }
            p = p->children[temp];
        }
        return p->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        TrieNode* p = root;
        for (int i=0; i<word.length(); i++){
            int temp = word[i]-'a';
            if (p->children[temp]==NULL){
                return false;
            }
            p = p->children[temp];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */