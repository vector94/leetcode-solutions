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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> myStack;
        
        vector<int> result;
        
        TreeNode* curNode = root;
        
        while (curNode || !myStack.empty()){
            if (curNode){
                myStack.push(curNode);
                curNode = curNode -> left;
            }
            
            else{
                TreeNode* tempNode = myStack.top();
                
                if (tempNode -> right){
                    curNode = tempNode -> right;
                }
                
                else{
                    result.push_back(tempNode -> val);
                    tempNode = myStack.top();
                    myStack.pop();
                    
                    while(!myStack.empty() && tempNode == myStack.top() -> right){
                        tempNode = myStack.top();
                        result.push_back(tempNode -> val);
                        myStack.pop();
                    }
                }
            }
        }
        
        return result;
    }
};