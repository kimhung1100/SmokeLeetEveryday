from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# O(N^2) solution: find the tail respectively and insert it to the head

# class Solution:
#     def reorderList(self, head: Optional[ListNode]) -> None:
#         """
#         Do not return anything, modify head in-place instead.
#         """
#         # case 1: list 0 node, one node, two node
#         if(head is None or head.next is None or head.next.next is None):
#             return head
        
#         # case 2: list 3 node
#         elif(head.next.next.next is None):
#             tail = head.next.next
#             head.next.next = None
#             tail.next = head.next
#             head.next = tail
#             return head
#         # case3: list 4 node and more
#         else:
#             self.helperRecurse(head)
#             return head
        
#     def helperRecurse(self, head: Optional[ListNode]) -> None:
#         # base case
#         if(head.next is None):
#             return
#         elif(head.next.next is None):
#             return 
#         # recursive case
#         else:
#             tail = self.getTail(head)
#             tail.next = head.next
#             head.next = tail
#             self.helperRecurse(head.next.next)
            
#     def getTail(self, node: Optional[ListNode]) -> Optional[ListNode]:
#         if(node.next.next is None):
#             temp = node.next # save the tail
#             node.next = None # cut off the tail
#             return temp
#         else:
#             return self.getTail(node.next)
        
# O(N) solution: find the middle node, reverse the second half, merge two halves
class Solution:
    # reverse linked list while looping
    def reverseList(self, node: Optional[ListNode]) -> Optional[ListNode]:
        if(node is None):
            return None
        prev = None
        curr = node
        next = None
        while(curr is not None):
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
            
        return prev
        
            
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # case 1: list 0 node, one node, two node
        if(head is None or head.next is None or head.next.next is None):
            return head
        
        # case 2: list 3 node
        elif(head.next.next.next is None):
            tail = head.next.next
            head.next.next = None
            tail.next = head.next
            head.next = tail
            return head
        
        # case3: list 4 node and more
        
        # find the middle node
        slow = head
        fast = head
        while(fast is not None and fast.next is not None):
            slow = slow.next
            fast = fast.next.next
        # slow is the middle node
        # reverse the second half
        newnode = self.reverseList(slow.next)
        slow.next = None # cut off the second half
        
        # merge two halves
        ans = head
        while(newnode is not None):
            temp = head.next
            head.next = newnode
            newnode = newnode.next
            head.next.next = temp
            head = temp
            
        return ans
    
# Test Case 1
# Input: 1->2->3->4->5
# Output: 1->5->2->4->3
def printList(head: Optional[ListNode]) -> None:
    while(head is not None):
        print(head.val, end = '->')
        head = head.next
    print('None')
    
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)
Solution().reorderList(head)
printList(head)
# Expected output: 1->5->2->4->3