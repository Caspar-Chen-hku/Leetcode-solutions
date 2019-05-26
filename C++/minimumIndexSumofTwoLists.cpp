class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> m;
        int minsum = INT_MAX;
        for (int i=0; i<list1.size(); i++){
            for (int j=0; j<list2.size(); j++){
                if (list1[i]==list2[j]){
                    m[list1[i]] = i+j;
                    minsum = min(minsum, i+j);
                    break;
                }
            }
        }
        vector<string> res;
        for (auto i:m){
            if (i.second==minsum){
                res.push_back(i.first);
            }
        }
        return res;
    }
};