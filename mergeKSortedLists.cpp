/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    int index = 0;
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = NULL;
        vector<ListNode*> ptrs;
        int l = lists.size();
        ListNode* temp;
        ListNode* current;
        for (int i=0; i<l; i++){
            if (lists[i]!=NULL){
                ptrs.push_back(lists[i]);
            }
        }
        if (ptrs.empty()) return NULL;
        else if (ptrs.size()==1){
            result = ptrs[0];
            return result;
        }
        result = smallest(ptrs);
        ptrs[index] = ptrs[index]->next;
        if (ptrs[index]==NULL){
            ptrs.erase(ptrs.begin()+index);
        }
        cout << index << " ";
        current = result;
        
        while (!ptrs.empty()){
            temp = smallest(ptrs);
            current->next = temp;
            cout << index << " ";
            ptrs[index] = ptrs[index]->next;
            current = current->next;
            if (ptrs[index]==NULL){
                ptrs.erase(ptrs.begin()+index);
                cout << "erased " << index << " ";
            }
        }
        return result;
    }
    
    ListNode* smallest(vector<ListNode*>& lists){
        int l = lists.size();
        if (l==0) return NULL;
        ListNode* ptr = lists[0];
        index = 0;
        for (int i=1; i<l; i++){
            if (lists[i]->val < ptr->val){
                ptr = lists[i];
                index = i;
            }
        }
        return ptr;
    }
};