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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1="", s2="";
        ListNode* curr = l1;
        while (curr!=NULL){
            s1.push_back(curr->val+'0');
            curr=curr->next;
        }
        curr = l2;
        while (curr!=NULL){
            s2.push_back(curr->val+'0');
            curr=curr->next;
        } 
        
        string result = addStrings(s1,s2);
        ListNode* head = new ListNode(result[0]-'0');
        curr = head;
        for (int i=0; i<result.length(); i++){
            if (i==result.length()-1){
                curr->next = NULL;
            }else{
                curr->next = new ListNode(result[i+1]-'0');
                curr = curr->next;   
            }
        }
        return head;
    }
    
    string addStrings(string num1, string num2) {
        int l1 = num1.length(), l2 = num2.length();
        if (l1<l2){
            num1 = string(l2-l1,'0')+num1;
        }else{
            num2 = string(l1-l2,'0')+num2;
        }
        int i = max(l1,l2)-1, out = 0, temp;
        string result(i+2,'0');
        while (i>=0){
            temp = (num1[i]-'0')+(num2[i]-'0')+out;
            result[i+1]= (temp%10)+'0';
            out = temp/10; i--;
        }
        if (out==0){
            return result.substr(1);
        }else{
            result[0] = (out+'0'); return result;    
        }
    }
};