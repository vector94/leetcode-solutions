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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        
        ListNode* preNode = dummy;
        ListNode* curNode = head;
        
        while (curNode && curNode -> next){
            ListNode* nextNode = curNode -> next;
            ListNode* nextNextNode = curNode -> next -> next;
            
            curNode -> next = nextNextNode;
            nextNode -> next = curNode;
            preNode -> next = nextNode;
            
            preNode = curNode;
            curNode = nextNextNode;
        }
        
        return dummy -> next;
    }
};