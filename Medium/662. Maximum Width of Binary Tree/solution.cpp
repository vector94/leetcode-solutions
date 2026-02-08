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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long> > myQueue;
        myQueue.push({root, 1});
        
        int result = 0;
        
        while (!myQueue.empty()){
            int size = myQueue.size();
            long long left, right;
            long long minId = myQueue.front().second;
            
            for (int i = 0; i < size; i++){
                TreeNode* curNode = myQueue.front().first;
                long long curId = myQueue.front().second - minId;
                myQueue.pop();
                
                if (i == 0){
                    left = curId;
                }
                if (i == size - 1){
                    right = curId;
                }
                
                if (curNode -> left){
                    myQueue.push({curNode -> left, 2 * curId + 1});
                }
                if (curNode -> right){
                    myQueue.push({curNode -> right, 2 * curId + 2});
                }
            }
            result = max(result, (int)(right - left + 1));
        }
        
        return result;
    }
};