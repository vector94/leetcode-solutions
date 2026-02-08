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
    bool isPalindrome(ListNode* head) {
        ListNode* prevNode = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode *ptr1, *ptr2;
        while (true){
            if (fast == NULL){
                ptr1 = slow;
                ptr2 = prevNode;
                break;
            }
            else if (fast -> next == NULL){
                ptr1 = slow -> next;
                ptr2 = prevNode;
                break;
            }
            fast = fast -> next -> next;
            ListNode* nextNode = slow -> next;
            slow -> next = prevNode;
            prevNode = slow;
            slow = nextNode;
        }
        while (ptr1 && ptr2){
            if (ptr1 -> val != ptr2 -> val){
                return false;
            }
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        return true;
    }
};