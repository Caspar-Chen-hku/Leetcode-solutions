class FreqStack {
public:
    
    map<int, int> freq; // map from element to frequency;
    int maxFreq = 0; 
    map<int, stack<int>> group; //map from frequency to the stack of elements;
    
    FreqStack() {
        
    }
    
    void push(int x) {
        freq[x]++;
        maxFreq = max(maxFreq, freq[x]);
        group[freq[x]].push(x);
    }
    
    int pop() {
        int res = group[maxFreq].top();
        freq[res]--;
        group[maxFreq].pop();
        if (group[maxFreq].empty()){
            maxFreq--;
        }
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */