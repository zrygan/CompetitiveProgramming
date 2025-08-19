from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        x = 0
        ln = ListNode()
        curr = ln

        while l1 or l2 or x:
            if l1:              
                x += l1.val     
                l1 = l1.next    
            if l2:
                x += l2.val
                l2 = l2.next

            curr.next = ListNode(x % 10)    
            x //= 10                        
            curr = curr.next                
        return ln.next