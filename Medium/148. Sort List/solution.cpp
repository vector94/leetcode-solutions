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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head -> next == NULL)   return head;
        ListNode* mid = MiddleNode(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return Merge(left, right);
    }
    
    ListNode* Merge(ListNode* list1, ListNode* list2){
        ListNode* head = new ListNode();
        ListNode* ptr = head;
        
        while (list1 && list2){
            if (list1 -> val < list2 -> val){
                ptr -> next = list1;
                list1 = list1 -> next;
            }
            else{
                ptr -> next = list2;
                list2 = list2 -> next;
            }
            ptr = ptr -> next;
        }
        
        if (list1){
            ptr -> next = list1;
        }
        else{
            ptr -> next = list2;
        }
        return head -> next;
    }
    
    ListNode* MiddleNode(ListNode* list){
        ListNode* slow = list;
        ListNode* fast = list;
        ListNode* prev = list;
        
        while (fast && fast -> next){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = NULL;
        return slow;
    }
};