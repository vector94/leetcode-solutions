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
        ListNode* dummyHead = new ListNode();
        dummyHead -> next = head;
        ListNode* preNode = dummyHead;
        ListNode* curNode = head;
        while (curNode && curNode -> next){
            if (curNode -> val == curNode -> next -> val){
                int curVal = curNode -> val;
                while (curNode && curNode -> val == curVal){
                    curNode = curNode -> next;
                }
                preNode -> next = curNode;   
            }
            else{
            preNode = curNode;
            curNode = curNode -> next;
            }
        }
        return dummyHead -> next;
    }
};