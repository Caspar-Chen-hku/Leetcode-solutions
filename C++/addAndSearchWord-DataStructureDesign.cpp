class Word{
    public:
    Word* children[26];
    bool isLeaf;
    
    Word(){
        for (int i=0; i<26; i++){
            children[i] = NULL;
        }
        isLeaf = false;
    }
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    
    Word* root;
        
    WordDictionary() {
        root = new Word;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Word* p = root;
        for (int i=0; i<word.length(); i++){
            int ind = word[i]-'a';
            if (p->children[ind]==NULL){
                p->children[ind] = new Word;
            }
            p = p->children[ind];
        }
        p->isLeaf = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchRec(word,root);
    }
    
    bool searchRec(string word, Word* node){
        int l = word.length();
        if (l==0){
            return node->isLeaf;
        }else if(word[0]=='.'){
            for (int i=0; i<26; i++){
                if (node->children[i]!=NULL && searchRec(word.substr(1),node->children[i])){
                    return true;
                }
            }
            return false;
        }else{
            Word* nextnode = node->children[word[0]-'a'];
            return nextnode!=NULL && searchRec(word.substr(1),nextnode);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */