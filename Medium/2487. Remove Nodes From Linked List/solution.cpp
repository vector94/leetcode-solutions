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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> myStack;
        
        ListNode* curNode = head;
        
        while (curNode != NULL){
            myStack.push(curNode);
            curNode = curNode -> next;
        }
        
        curNode = myStack.top();
        myStack.pop();
        int maxValue = curNode -> val;
        
        while (!myStack.empty()){
            ListNode* prevNode = myStack.top();
            myStack.pop();
            
            if (prevNode -> val >= maxValue){
                maxValue = max(maxValue, prevNode -> val);
                prevNode -> next = curNode;
                curNode = prevNode;
            }
        }
        
        return curNode;
    }
};