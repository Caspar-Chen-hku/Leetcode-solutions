class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int i=0, temp;
        while (i<input.length()){
            temp = input.find_first_of("+-*/",i);
            if (temp==-1){
                if (res.empty()){
                    res.push_back(stoi(input));   
                }
                return res;
            }else{
                combine(diffWaysToCompute(input.substr(0,temp)),
                       diffWaysToCompute(input.substr(temp+1)),
                       input[temp],res);
            }
            i = temp+1;
        }
        return res;
    }
    
    void combine(vector<int> left, vector<int> right, char op, vector<int>& res){
        for (int i=0; i<left.size(); i++){
            for (int j=0; j<right.size(); j++){
                if (op=='+'){
                    res.push_back(left[i]+right[j]);
                }else if (op=='-'){
                    res.push_back(left[i]-right[j]);
                }else if (op=='*'){
                    res.push_back(left[i]*right[j]);
                }else if (right[j]!=0){
                    res.push_back(left[i]/right[j]);
                }
            }
        }
    }
};