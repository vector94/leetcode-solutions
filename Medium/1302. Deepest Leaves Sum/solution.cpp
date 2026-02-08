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
    int deepestLeavesSum(TreeNode* root) {
        if (root == NULL)   return 0;
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        
        while (!myQueue.empty()){
            int curSum = 0;
            int queueSize = myQueue.size();
            
            for (int i = 0; i < queueSize; i++){
                TreeNode* curNode = myQueue.front();
                myQueue.pop();
                curSum += curNode -> val;
                
                if (curNode -> left){
                    myQueue.push(curNode -> left);
                }
                if (curNode -> right){
                    myQueue.push(curNode -> right);
                }
            }
            if (myQueue.empty())    return curSum;
        }
        
        return 0;
    }
};