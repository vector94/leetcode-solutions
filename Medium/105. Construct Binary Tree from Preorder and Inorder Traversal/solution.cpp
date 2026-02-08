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
    
    TreeNode* buildTreeHelper(int &index, int left, int right, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &myMap){
        if (left > right)   return NULL;
        int curValue = preorder[index++];
        TreeNode *curNode = new TreeNode(curValue);
        curNode -> left = buildTreeHelper(index, left, myMap[curValue] - 1, preorder, inorder, myMap);
        curNode -> right = buildTreeHelper(index, myMap[curValue] + 1, right, preorder, inorder, myMap);
        return curNode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        unordered_map<int, int> myMap;
        for (int i = 0; i < n; i++){
            myMap[inorder[i]] = i;
        }
        int index = 0;
        return buildTreeHelper(index, 0, n - 1, preorder, inorder, myMap);
    }
};