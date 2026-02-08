/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head -> next == NULL)   return head;
        
        ListNode *head1, *head2;
        ListNode *ptr1 = new ListNode();
        ListNode *ptr2 = new ListNode();
        
        ListNode *tail;
        head1 = ptr1;
        head2 = ptr2;
        
        while (head){
            ptr1 -> next = head;
            ptr2 -> next = head -> next;
            tail = head;
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
            if (head -> next == NULL) break;
            head = head -> next -> next;
        }
        
        head1 = head1 -> next;
        tail -> next = head2 -> next;
        
        return head1;
    }
};