class ExamRoom {
public:
    
    vector<int> seats;
    int num;
    
    ExamRoom(int N) {
        num = N;
    }
    
    int seat() {
        if (seats.empty()){
            seats.push_back(0); return 0;
        }else{
            int maxSeat = 0, maxDis = seats[0], toinsert = 0;
            for (int i=0; i<seats.size()-1; i++){
                if ((seats[i+1]-seats[i])/2 > maxDis){
                    maxDis = (seats[i+1]-seats[i])/2;
                    maxSeat = (seats[i+1]+seats[i])/2;
                    toinsert = i+1;
                }
            }
            if (num-1-seats.back()>maxDis){
                seats.push_back(num-1);
                return num-1;
            }else{
                seats.insert(seats.begin()+toinsert, maxSeat);
                return maxSeat;   
            }
        }
    }
    
    void leave(int p) {
        int i=0, j=seats.size()-1, mid;
        while (i<=j){
            mid = (i+j)/2;
            if (seats[mid]==p){
                seats.erase(seats.begin()+mid); return;
            }else if (seats[mid]>p) j=mid-1;
            else i=mid+1;
        }
        return;
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */