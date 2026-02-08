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
    ListNode* doubleIt(ListNode* head) {
        vector<int> num;
        
        while (head){
            num.push_back(head -> val);
            head = head -> next;
        }
        
        int carry = 0;
        ListNode* curNode = NULL;
        
        for (int i = num.size() - 1; i >= 0; i--){
            int curNum = num[i] * 2 + carry;
            ListNode* prevNode = new ListNode(curNum % 10, curNode);
            curNode = prevNode;
            carry = curNum / 10;
        }
        
        while (carry){
            ListNode* prevNode = new ListNode (carry % 10, curNode);
            curNode = prevNode;
            carry /= 10;
        }
        
        return curNode;
    }
};