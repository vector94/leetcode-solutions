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
    void reorderList(ListNode* head) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        ListNode* firstList = head;
        
        while (fast && fast -> next && fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        ListNode* secondList = slow -> next;
        slow -> next = NULL;
        
        ListNode* pre = NULL;
        ListNode* cur = secondList;
        
        while (cur){
            ListNode* next = cur -> next;
            cur -> next = pre;
            pre = cur;
            secondList = cur;
            cur = next;
        }
        
        ListNode* result = firstList;
        
        while (secondList){
            ListNode* firstListNext = firstList -> next;
            ListNode* secondListNext = secondList -> next;
            firstList -> next = secondList;
            secondList -> next = firstListNext;
            firstList = firstListNext;
            secondList = secondListNext;
        }
    }
};