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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if (left == right)  return head;
        
        ListNode* preNode = head;
        ListNode* tailNode = head;
        
        ListNode* curNode = head;
        
        int i = 1;
        ListNode *leftNode, *rightNode;
        while (curNode){
            if (i < left){
                preNode = curNode;
            }
            else if (i == left){
                leftNode = curNode;
            }
            else if (i == right){
                rightNode = curNode;
                tailNode = rightNode -> next;
                break;
            }
            curNode = curNode -> next;
            i++;
        }
        
        ListNode* pre = curNode;
        ListNode* leftHead = leftNode;
        
        while (leftNode != rightNode){
            ListNode* next = leftNode -> next;
            leftNode -> next = pre;
            
            pre = leftNode;
            leftNode = next;
        }
        leftNode -> next = pre;
        
        if (left == 1){
            head = leftNode;
        }
        else {
            preNode -> next = leftNode;
        }
        leftHead -> next = tailNode;
        
        return head;
    }
};
