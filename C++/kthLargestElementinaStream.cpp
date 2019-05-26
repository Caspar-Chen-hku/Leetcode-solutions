class KthLargest {
public:
    
    vector<int> eles;
    int num;
    
    KthLargest(int k, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size()>=k){
            eles.insert(eles.end(), nums.begin()+nums.size()-k, nums.end());   
        }else{
            eles.insert(eles.end(), nums.begin(), nums.end()); 
        }
        eles.push_back(INT_MAX);
        num = k;
    }
    
    int add(int val) {
        int temp = min(num, (int) eles.size()-1);
        for (int i=0; i<=temp; i++){
            if (eles[i]>=val){
                eles.insert(eles.begin()+i, val);
                if (eles.size()>num+1){
                    eles.erase(eles.begin());   
                }
                break;
            }
        }
        return eles[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */