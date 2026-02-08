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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, bool> present;

        for (int n : nums){
            present[n] = true;
        }

        ListNode* curNode = head;
        ListNode* prevNode;

        while (curNode != NULL){
            int curVal = curNode -> val;
            cout << curVal << endl;
            if (present[curVal]){
                if (curNode == head){
                    ListNode* nextNode = curNode -> next;
                    curNode = nextNode;
                    head = curNode;
                }
                else{
                    ListNode* nextNode = curNode -> next;
                    prevNode -> next = nextNode;
                    curNode = nextNode;
                }
            }
            else{
                prevNode = curNode;                
                curNode = curNode -> next;
            }
        }

        return head;
    }
};