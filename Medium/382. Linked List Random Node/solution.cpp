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
private:
    int length = 0;
    ListNode* head;
public:
    Solution(ListNode* head) {
        this -> head = head;
        ListNode* curNode = head;
        
        while (curNode){
            length++;
            curNode = curNode -> next;
        }
    }
    
    int getRandom() {
        int randIndex = rand() % length;
        ListNode* curNode = head;
        
        for (int i = 0; i < randIndex; i++){
            curNode = curNode -> next;
        }
        
        return curNode -> val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */