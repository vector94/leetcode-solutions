/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    
    public ListNode ReverseListHelper(ListNode preNode, ListNode currentNode){
        if (currentNode == null){
            return preNode;
        }
        ListNode nextNode = currentNode.next;
        currentNode.next = preNode;
        return ReverseListHelper(currentNode, nextNode);
    }
    
    public ListNode ReverseList(ListNode head) {
        ListNode preNode = null;
        return ReverseListHelper(preNode, head);
    }
}