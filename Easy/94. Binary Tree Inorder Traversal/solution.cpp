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
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> myStack;
        TreeNode* curNode = root;
        
        vector<int> result;
        
        while (curNode || !myStack.empty()){
            if (curNode){
                myStack.push(curNode);
                curNode = curNode -> left;
            }
            else{
                curNode = myStack.top();
                myStack.pop();
                result.push_back(curNode -> val);
                curNode = curNode -> right;
            }
        }
        
        return result;
    }
};