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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        bool flag = 'ture';
        ListNode *temp, *ret;
        while (l1 && l2){
            if (l1 -> val <= l2 -> val){
                if (flag){
                    flag = false;
                    ret = temp = l1;
                }
                else{
                    temp -> next = l1;
                    temp = temp -> next;
                }
                l1 = l1 -> next;
            }
            else{
                if (flag){
                    flag = false;
                    ret = temp = l2;
                }
                else{
                    temp -> next = l2;
                    temp = temp -> next;
                }
                l2 = l2 -> next;
            }
        }
        while (l1){
            if (flag){
                flag = false;
                ret = temp = l1;
            }
            else{
                temp -> next = l1;
                temp = temp -> next;
            }
            l1 = l1 -> next;
        }
        while (l2){
            if (flag){
                flag = false;
                ret = temp = l2;
            }
            else{
                temp -> next = l2;
                temp = temp -> next;
            }
            l2 = l2 -> next;
        }
        return ret;
    }
};