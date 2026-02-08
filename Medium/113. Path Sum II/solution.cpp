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
    vector<vector<int> > ret;
    vector<int> v;
    
    void solve(TreeNode* cur, int targetSum, int curSum = 0){
        curSum += cur -> val;
        if (cur -> left == NULL && cur -> right == NULL){
            if (curSum == targetSum){
                ret.push_back(v);
            }
            return;
        }
        if (cur -> left != NULL){
            v.push_back(cur -> left -> val);
            solve(cur -> left, targetSum, curSum);
            v.pop_back();
        }
        if (cur -> right != NULL){
            v.push_back(cur -> right -> val);
            solve(cur -> right, targetSum, curSum);
            v.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL){
            return ret;
        }
        v.push_back(root -> val);
        solve(root, targetSum);
        return ret;
    }
};