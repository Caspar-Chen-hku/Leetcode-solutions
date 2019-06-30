class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        queue<int> inds;
        sort(deck.begin(), deck.end());
        for (int i=0; i<n; i++){
            inds.push(i);
        }
        vector<int> result(n, 0);
        for (int i=0; i<n; i++){
            result[inds.front()] = deck[i];
            inds.pop();
            inds.push(inds.front());
            inds.pop();
        }
        return result;
    }
};