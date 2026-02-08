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
    
    int findTiltHelper(TreeNode* node, int &sum){
        if (node == NULL)   return 0;
        int leftSum = findTiltHelper(node -> left, sum);
        int rightSum = findTiltHelper(node -> right, sum);
        sum += abs(leftSum - rightSum);
        return node -> val + leftSum + rightSum;
    }
    
    int findTilt(TreeNode* root) {
        int sum = 0;
        
        findTiltHelper(root, sum);
        
        return sum;        
    }
};