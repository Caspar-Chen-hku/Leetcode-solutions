class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int> cards;
        for (int h:hand){
            cards[h]++;
        }
        int count = 0, cur;
        while (!cards.empty()){
            count = 0; cur = cards.begin()->first;
            for (int i=cur; i<cur+W; i++){
                if (cards.count(i)==0) return false;
                else {
                    cards[i]--;
                    if (cards[i]==0) cards.erase(i);
                }
            }
        }
        return true;
    }
};