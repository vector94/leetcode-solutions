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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> myQueue;
        vector<double> result;
        
        myQueue.push(root);
        
        while (!myQueue.empty()){
            int curSize = myQueue.size();
            double avg = 0;
            for (int i = 0; i < curSize; i++){
                TreeNode* curNode = myQueue.front();
                myQueue.pop();
                avg += curNode -> val;
                if (curNode -> left){
                    myQueue.push(curNode -> left);
                }
                if (curNode -> right){
                    myQueue.push(curNode -> right);
                }
            }
            avg /= curSize;
            result.push_back(avg);
        }
        
        return result;
    }
};