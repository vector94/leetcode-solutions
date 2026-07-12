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
    ListNode* reverseListHelper(ListNode* preNode, ListNode* curNode){
        if (curNode == NULL)    return preNode;
        ListNode* nextNode = curNode -> next;
        curNode -> next = preNode;
        
        return reverseListHelper(curNode, nextNode);
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverseListHelper(NULL, head);
    }
};