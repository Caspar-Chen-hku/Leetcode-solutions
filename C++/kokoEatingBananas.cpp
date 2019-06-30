class Solution {
public:
int num_hours(vector<int>& piles, int cap)
{
    int ans = 0;
    for(int i=0;i<piles.size();++i)
    {
        ans += piles[i]/cap + min(1, piles[i]%cap);
    }
    return ans;
}

int minEatingSpeed(vector<int>& piles, int H) {
    int start = 1;
    int end = piles[0];
    
    for(int i=0; i<piles.size(); ++i)
        end = max(end, piles[i]);
    int ans = 1;
    
    while(start<=end)
    {
        int mid = (start+end)/2;
        int x = num_hours(piles, mid);
        if(x>H)
            start = mid+1;
        else
        {
            ans = mid;
            end = mid-1;
        }
    }
    return ans;
}
};