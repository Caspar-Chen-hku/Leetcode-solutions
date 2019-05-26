class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> numbers;
        int i = 0, j = 0;
        int l1 = pushed.size(), l2 = popped.size();
        while (i<l1 && j<l2){
            numbers.push(pushed[i]); i++;
            while (!numbers.empty() && numbers.top()==popped[j]){
                numbers.pop(); j++;
            }
        }
        return numbers.empty();
    }
};