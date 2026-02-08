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
        ListNode* newHead = new ListNode();
        newHead -> next = head;
        ListNode* node = newHead;
        while (node -> next && node -> next -> next){
            ListNode* temp = node -> next;
            node -> next = node -> next -> next;
            temp -> next = node -> next -> next;
            node -> next -> next = temp;
            node = node -> next -> next;
        }
        return newHead -> next;
    }
};

// node -> [1] -> [2] -> [3] -> [NULL]

// temp = [1]
// node-> [2]