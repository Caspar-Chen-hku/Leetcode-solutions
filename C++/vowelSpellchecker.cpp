class Solution {
public:
    
    string vowels = "aeiouAEIOU";
    
    string lowerize(string origin){
        string result;
        for (char o:origin){
            result.push_back(tolower(o));
        }
        return result;
    }
    
    string devowel(string origin){
        string result;
        for (char o:origin){
            if (vowels.find(o)!=string::npos){
                result.push_back('*');
            }else{
                result.push_back(tolower(o)); 
            }
        }
        return result;
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string> words(wordlist.begin(), wordlist.end());
        map<string,string> wordsLower;
        map<string,string> wordsSwap;
        vector<string> result;
        for (int i=wordlist.size()-1; i>=0; i--){
            wordsLower[lowerize(wordlist[i])] = wordlist[i];
            wordsSwap[devowel(wordlist[i])] = wordlist[i];
        }
        for (string q:queries){
            if (words.find(q)!=words.end()){
                result.push_back(q);
            } else{
                string temp = lowerize(q);
                if (wordsLower.count(temp)>0)
                    result.push_back(wordsLower[temp]);
                else{
                    temp = devowel(q);
                    if (wordsSwap.count(temp)>0){
                        result.push_back(wordsSwap[temp]);
                    }else{
                        result.push_back("");
                    }
                }
            }
        }
        return result;
    }
};