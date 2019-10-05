class Solution {
private:
    void extract(const string& input, int& idx, bool& start, int& time) {
        int i=input.find(":"), last=0;
        idx = stoi(input.substr(last, i-last));
        last = i+1;
        i = input.find(":", last);
        start = (input.substr(last,i-last) == "start");
        last = i+1;
        time = stoi(input.substr(last, input.size()-last));
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<pair<int, int>> sk;
        vector<int> res(n), vsk;
        int idx, time;
        bool start;
        vsk.push_back(0);
        for (auto& v : logs) {
            extract(v, idx, start, time);
            if (start) {
                sk.push_back({idx, time});
                vsk.push_back(0);
            } else {
                auto p = sk.back();
                sk.pop_back();
                int val = vsk.back();
                vsk.pop_back();
                res[idx] += time - p.second + 1 - val;
                vsk.back() += time - p.second + 1;
            }
        }
        return res;
    }
};