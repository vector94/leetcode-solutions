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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> myQueue;
        TreeNode* curNode = root;
        
        myQueue.push(curNode);
        
        while (!myQueue.empty()){
            curNode = myQueue.front();
            myQueue.pop();
            
            if (curNode -> right != NULL){
                myQueue.push(curNode -> right);
            }
            if (curNode -> left != NULL){
                myQueue.push(curNode -> left);
            }
        }
        
        return curNode -> val;
    }
};