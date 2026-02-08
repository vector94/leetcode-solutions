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
    
    ListNode* getTail(ListNode* head, int &length){
        ListNode* tail;
        while (head){
            tail = head;
            head = head -> next;
            length++;
        }
        return tail;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (head == NULL)   return head;
        
        int length = 0;
        ListNode* tail = getTail(head, length);
        k %= length;
        
        if (k == 0) return head;
        
        ListNode* newTail = head;
        for (int i = 1; i < length - k; i++){
            newTail = newTail -> next;
        }
        
        ListNode* newHead = newTail -> next;
        newTail -> next = NULL;
        tail -> next = head;
        
        return newHead;
        
    }
};