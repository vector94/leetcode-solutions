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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int totalNode = 0;
        ListNode* curNode = head;
        
        while (curNode){
            totalNode++;
            curNode = curNode -> next;
        }
        
        ListNode* newHead = new ListNode(-1);
    
        ListNode* preTail = newHead;
        ListNode *curTail, *preNode;
        
        preNode = preTail;
        curTail = curNode = head;
        
        int curCnt = 0;
        
        while (curNode){
            if (totalNode < k){
                break;
            }
            
            curCnt++;
            ListNode* nextNode = curNode -> next;
            curNode -> next = preNode;
            preNode = curNode;
            
            if (curCnt == k){
                curTail -> next = nextNode;
                preTail -> next = curNode;
                
                preTail = curTail;
                curTail = nextNode;
                
                totalNode -= k;
                curCnt = 0;
            }
            
            curNode = nextNode;
        }
        
        return newHead -> next;
    }
};