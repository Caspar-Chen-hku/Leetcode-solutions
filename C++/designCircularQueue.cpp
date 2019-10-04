class MyCircularQueue {
public:
    vector<int> q;
    int f = -1, r = -1, len;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q = vector<int>(k);
        len = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (f==-1){
            q[0] = value; f = 0; r = 1%len;
        }else if (f==r){
            return false;
        }else{
            q[r] = value; r = (r+1)%len;
        }
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (f==-1){
            return false;
        }
        f = (f+1)%len;
        if (f==r){
            f = -1; r = -1;
        }
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (f==-1) return -1;
        else return q[f];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (f==-1) return -1;
        else if (r>0){
            return q[r-1];
        }else{
            return q.back();
        }
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return f==-1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return f!=-1&&f==r;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */