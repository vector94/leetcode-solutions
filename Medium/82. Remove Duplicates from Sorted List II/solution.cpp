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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tempHead = new ListNode();
        tempHead -> next = head;
        
        ListNode* curNode = head;
        ListNode* preNode = tempHead;
        
        while (curNode && curNode -> next){
            if (curNode -> val == curNode -> next -> val){
                ListNode* tempNode = curNode -> next;
                while (tempNode && tempNode -> val == curNode -> val){
                    tempNode = tempNode -> next;
                }
                preNode -> next = tempNode;
                curNode = tempNode;
            }
            else{
                preNode = curNode;
                curNode = curNode -> next;
            }
        }
        return tempHead -> next;
    }
};