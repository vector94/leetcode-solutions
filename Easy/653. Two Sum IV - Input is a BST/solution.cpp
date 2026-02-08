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
    
    bool Find(TreeNode* currentNode, int key){
        if (currentNode == NULL)   return false;
        if (currentNode -> val == key) return true;
        if (key < currentNode -> val){
            return Find(currentNode -> left, key);
        }
        else{
            return Find(currentNode -> right, key);
        }
    }
    
    bool findTargetHelper(TreeNode* root, TreeNode* currentNode, int k){
        if (currentNode == NULL)   return false;
        int need = k - currentNode -> val;
        if (need != currentNode -> val && Find(root, need)){
            return true;
        }
        return findTargetHelper(root, currentNode -> left, k) || findTargetHelper(root, currentNode -> right, k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        return findTargetHelper(root, root, k);
    }
};