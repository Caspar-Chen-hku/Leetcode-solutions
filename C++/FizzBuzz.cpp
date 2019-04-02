class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        string temp; bool exist;
        for (int i=1; i<=n; i++){
            temp = ""; exist = false;
            if (i%3==0){
                temp += "Fizz";
                exist = true;
            }
            if (i%5==0){
                temp += "Buzz";
                exist=true;
            }
            if (!exist){
                temp = to_string(i);
            }
            result.push_back(temp);
        }
        return result;
    }
};