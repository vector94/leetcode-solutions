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
    
    void pushLeft(TreeNode* node, stack<TreeNode*> &myStack){
        if (node == NULL)   return;
        while (node){
            myStack.push(node);
            node = node -> left;
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> result;
        
        stack<TreeNode*> myStack1, myStack2;
        
        pushLeft(root1, myStack1);
        pushLeft(root2, myStack2);
        
        while (!myStack1.empty() && !myStack2.empty()){
            if (myStack1.top() -> val < myStack2.top() -> val){
                TreeNode* node = myStack1.top();
                myStack1.pop();
                result.push_back(node -> val);
                
                pushLeft(node -> right, myStack1);
            }
            else{
                TreeNode* node = myStack2.top();
                myStack2.pop();
                result.push_back(node -> val);
                
                pushLeft(node -> right, myStack2);
            }
        }
        
        stack<TreeNode*> myStack = (myStack1.empty() ? myStack2 : myStack1);
        
        while (!myStack.empty()){
            TreeNode* node = myStack.top();
            myStack.pop();
            result.push_back(node -> val);
            
            pushLeft(node -> right, myStack);
        }
        
        return result;
    }
};