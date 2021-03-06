class MyLinkedList {
public:
    
    vector<int> list;
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        list.clear();    
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index<list.size()){
            return list[index];
        }else{
            return -1;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        list.insert(list.begin(), val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        list.push_back(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index<0){
            addAtHead(val);
        }else if (index<=list.size()){
            list.insert(list.begin()+index, val);
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index<list.size()){
            list.erase(list.begin()+index);   
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */