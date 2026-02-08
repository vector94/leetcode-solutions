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
private:
    TreeNode *first;
    TreeNode *middle;
    TreeNode *last;
    TreeNode *prev;
public:
    
    void Inorder(TreeNode* curNode){
        if (curNode == NULL)    return;
        
        Inorder(curNode -> left);
        
        if (curNode -> val < prev -> val){
            if (first == NULL){
                first = prev;
                middle = curNode;
            }
            else{
                last = curNode;
            }
        }
        prev = curNode;
        Inorder(curNode -> right);
    }
    
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        Inorder(root);
        
        if (last != NULL){
            swap(first -> val, last -> val);
        }
        else{
            swap(first -> val, middle -> val);
        }
    }
};