class Solution {
public:
    
    vector<vector<string>> rule{
     {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"},  
     {"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen",
      "Sixteen","Seventeen","Eighteen","Nineteen"},
    {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"},
    {""," Thousand"," Million"," Billion"}
    };
    
    string numberToWords(int num) {
        vector<int> res;
        int n = num;
        while (n>0){
            res.push_back(n%1000);
            n /= 1000;
        }
        string temp, result = "";
        for (int i=0; i<res.size(); i++){
            if (res[i]==0) continue;
            temp = convert(res[i]);
            result = temp + rule[3][i] + (result.empty() ? "" : " " + result);   
        }
        return (result.empty() ? "Zero" : result);
    }
    
    string convert(int n){
        string result;
        int temp = n%100;
        if (temp<20){
            if (temp>0){
                result = rule[temp/10][temp%10];   
            }
            n /= 100;
        }else{
            temp = n%10;
            if (temp>0){
                result = rule[0][temp];
            }
            n /= 10; temp = n%10;
            if (temp>0){
                result = rule[2][temp] + (result.empty() ? "" : " " + result);   
            }
            n /= 10;
        }
        if (n>0){
            result = rule[0][n] + " Hundred" + (result.empty() ? "" : " " + result);
        }
        return result;
    }
};