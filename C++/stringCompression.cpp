class Solution {
public:
    int compress(vector<char>& chars) {
        int count=0;
        int i=0, temp, num;
        while (i<chars.size()){
            temp=find(chars,i);
            if (temp==i){
                i++; count++;
            }else{
                chars.erase(chars.begin()+i+1,chars.begin()+temp+1);
                num = temp-i+1;
                temp = i+1;
                while (num>0){
                    chars.insert(chars.begin()+i+1,num%10+'0');
                    num /= 10;
                    count++; temp++;
                }
                count++; i=temp;
            }
        }
        return count;
    }
    
    int find(vector<char>& chars, int target){
        int i;
        for (i=target; i<chars.size(); i++){
            if (i==chars.size()-1 || chars[i+1]!=chars[i]) return i;
        }
        return i;
    }
};