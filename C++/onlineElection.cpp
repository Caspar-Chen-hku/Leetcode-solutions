class TopVotedCandidate {
public:
    
    vector<int> time;
    vector<int> lead;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int l = persons.size();
        time = times;
        lead = vector<int>(l , 0);
        lead[0] = persons[0];
        map<int,int> votes;
        votes[persons[0]] = 1;
        int curLead = 1, leadPerson = persons[0];
        for (int i=1; i<l; i++){
            if (++votes[persons[i]] >= curLead){
                curLead = votes[persons[i]];
                leadPerson = persons[i];
            }
            lead[i] = leadPerson;
        }
    }
    
    int q(int t) {
        int l = time.size(), i = 0, j = l-1, mid;
        while (i<=j){
            mid = (i+j)/2;
            if (time[mid]<=t && (mid==l-1 || time[mid+1]>t)){
                break;
            }else if (time[mid]>t){
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return lead[mid];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */