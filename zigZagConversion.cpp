class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows>s.length()||numRows==1) return s;
        string* arr = new string[numRows];
        for (int i=0; i<numRows; i++){
            arr[i] = "";
        }
        bool add = true;
        int index = 0;
        for (int i=0; i<s.length(); i++){
            arr[index] += s.substr(i,1);
            if (index==0) add=true;
            else if (index==numRows-1) add=false;
            if (add) index++;
            else index--;
        }
        string result = "";
        for (int i=0; i<numRows; i++){
            result += arr[i];
        }
        delete[] arr;
        return result;
    }
};