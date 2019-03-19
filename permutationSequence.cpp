class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> seq;
        for (int i=1; i<=n; i++){
            seq.push_back(i+'0');
        }
        string result(n,'0');
        int* fac = new int[n];
        fac[0] = 1;
        for (int i=1; i<n; i++){
            fac[i] = fac[i-1]*i;
        }
        int index, num=n;
        k--;
        for (int i=0; i<num; i++){
            index = k/fac[n-1];
            result[i] = seq[index];
            seq.erase(seq.begin()+index);
            k = k%fac[n-1]; n--; 
        }
        return result;
    }
};