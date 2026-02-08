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
    
    TreeNode* buildTreeHelper(int &index, int left, int right, vector<int> &postorder, unordered_map<int, int> &inorderIndex){
        if (left > right)   return NULL;
        
        int curVal = postorder[index--];
        
        TreeNode* curNode = new TreeNode(curVal);
        
        curNode -> right = buildTreeHelper(index, inorderIndex[curVal] + 1, right, postorder, inorderIndex);
        curNode -> left = buildTreeHelper(index, left, inorderIndex[curVal] - 1, postorder, inorderIndex);
        
        return curNode;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndex;
        
        for (int i = 0; i < inorder.size(); i++){
            inorderIndex[inorder[i]] = i;
        }
        
        int postorderIndex = postorder.size() - 1;
        
        return buildTreeHelper(postorderIndex, 0, inorder.size() - 1, postorder, inorderIndex);
    }
};