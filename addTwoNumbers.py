# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    #iterate through the two linked lists, add the corresponding values,
    #create a new node for every added value and connect to the resulting list
    def addTwoNumbers(self, l1: 'ListNode', l2: 'ListNode') -> 'ListNode':
        result = ListNode(0)
        num = 0     #num stores the carry out digit
        current = result
        while l1!=None or l2!=None or num!=0:
            temp=num
            if l1!=None:
                temp+=l1.val
            if l2!=None:
                temp+=l2.val
            #suppose the current two digits to add are a and b, then
            #temp = a + b + carry-out-from-last
            current.val = temp%10
            num = int(temp/10)
            if (l1!=None and l1.next!=None) or (l2!=None and l2.next!=None) or num!=0:
                current.next = ListNode(0)
                current =current.next
            if (l1!=None):
                l1 = l1.next
            if l2!=None:
                l2 = l2.next
        current=None
        return result