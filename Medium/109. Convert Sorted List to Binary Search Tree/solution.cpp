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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    ListNode* getMiddleNode(ListNode* head, ListNode*  tail){
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != tail && fast -> next != tail){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    TreeNode* buildTree(ListNode* head, ListNode* tail){
        if (head == tail){
            return NULL;
        }
        
        ListNode* middleNode = getMiddleNode(head, tail);
        
        TreeNode* rootNode = new TreeNode(middleNode -> val, buildTree(head, middleNode), buildTree(middleNode -> next, tail));
        return rootNode;
    } 
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)   return NULL;
        
        return buildTree(head, NULL);
    }
};