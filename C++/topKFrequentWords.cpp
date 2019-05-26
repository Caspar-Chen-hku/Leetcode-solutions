struct Compare {
    constexpr bool operator()(pair<int, string> const & a,
                              pair<int, string> const & b) const noexcept
    { return a.first < b.first || (a.first == b.first && a.second > b.second); }
};

class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for (string w:words){
            m[w]++;
        }
        priority_queue<pair<int,string>,
                   std::vector<pair<int,string> >,
                   Compare> q;
        for (auto e:m){
            q.push(make_pair(e.second, e.first));
        }
        vector<string> res;
        while (k>0){
            res.push_back(q.top().second);
            q.pop(); k--;
        }
        return res;
    }
};