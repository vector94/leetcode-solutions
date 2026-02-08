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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = new ListNode(INT_MIN);
        newHead -> next = head;
        head = newHead;
        
        ListNode* prevPtr1 = head;
        ListNode* ptr1 = head -> next;
        while (ptr1){
            
            ListNode* prevPtr2 = head;
            ListNode* ptr2 = head -> next;
            
            while (ptr2 != ptr1 && ptr2 -> val < ptr1 -> val){
                prevPtr2 = ptr2;
                ptr2 = ptr2 -> next;
            }
            
            if (ptr2 != ptr1){
                ListNode* temp = ptr1 -> next;
                prevPtr2 -> next = ptr1;
                ptr1 -> next = ptr2;
                prevPtr1 -> next = temp;
                ptr1 =  temp;
            }
            else{
                prevPtr1 = ptr1;
                ptr1 = ptr1 -> next;
            }
        }
        
        return head -> next;
    }
};