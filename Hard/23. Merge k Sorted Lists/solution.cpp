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
    
    struct cmp{
       bool operator()(ListNode* x, ListNode* y) {
           return (x -> val > y -> val);
       }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*>, cmp> myPQ;
        for (auto list : lists){
            if (list){
                myPQ.push(list);
            }
        }
        
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while (!myPQ.empty()){
            ListNode* cur = myPQ.top();
            myPQ.pop();
            tail -> next = cur;
            tail = tail -> next;
            
            cur = cur -> next;
            if (cur){
                myPQ.push(cur);
            }
        }
        
        return head -> next;
    }
};