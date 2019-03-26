class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (version1.empty() && version2.empty()){
            return 0;
        }else if (version1.empty()){
            version1 = "0";
        }else if (version2.empty()){
            version2 = "0";
        }
        int p1 = version1.find(".");
        int p2 = version2.find(".");
        int temp = stoi(version1) - stoi(version2);
        if (temp==0){
            if (p1==-1 && p2==-1){
                return 0;
            }else if (p1==-1){
                version1 = "0";
                version2 = version2.substr(p2+1);
            }else if (p2==-1){
                version2 = "0";
                version1 = version1.substr(p1+1);
            }else{
                version1 = version1.substr(p1+1);
                version2 = version2.substr(p2+1);
            }
            return compareVersion(version1,version2);
        }else if (temp<0){
            return -1;
        }else{
            return 1;
        }
    }
};