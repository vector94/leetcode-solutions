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
    
    void pathSumHelper(TreeNode* root, int &targetSum, int &sum, int &result, unordered_map<int, int> &hashMap){
        if (root == NULL){
            return;
        }
        hashMap[sum]++;
        sum += root -> val;
        int need = sum - targetSum;
        result += hashMap[need];
        
        pathSumHelper(root -> left, targetSum, sum, result, hashMap);
        pathSumHelper(root -> right, targetSum, sum, result, hashMap);
        
        sum -= root -> val;
        hashMap[sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)   return 0;
        
        unordered_map<int, int> hashMap;
        
        int sum = 0;
        int result = 0;
        pathSumHelper(root, targetSum, sum, result, hashMap);
        
        return result;
    }
};