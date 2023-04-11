# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# recursive

class Solution:
    def helperRecursive(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if(head is None):
            return None
        if(head.next is None):
            return head
        nxtNode = head.next.next
        curNode = head.next
        curNode.next = head
        head.next = None
        reverseList = self.helperRecursive(nxtNode)
        if(reverseList is not None):
            nxtNode.next = curNode
            return reverseList
        else:
            return curNode
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        newHead = self.helperRecursive(head)
        return newHead