class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        vector<int> ind{0,0};
        vector<int> numa{0,0};
        vector<int> numb{0,0};
        ind[0] = a.find("+");
        ind[1] = b.find("+");
        numa[0] = stoi(a.substr(0,ind[0]));
        numa[1] = stoi(a.substr(ind[0]+1));
        numb[0] = stoi(b.substr(0,ind[1]));
        numb[1] = stoi(b.substr(ind[1]+1));
        return to_string(numa[0]*numb[0]-numa[1]*numb[1]) + "+"
            + to_string(numa[0]*numb[1]+numa[1]*numb[0]) + "i";
    }
};