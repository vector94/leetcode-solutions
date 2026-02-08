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

    string findDuplicateSubtreesHelper(TreeNode* curNode, unordered_map<string, int> &treeCount, vector<TreeNode*> &result){
        if (curNode == NULL)
            return "#";
        
        string leftSubTree = findDuplicateSubtreesHelper(curNode -> left, treeCount, result);
        string rightSubTree = findDuplicateSubtreesHelper(curNode -> right, treeCount, result);

        string curTree = "(" + leftSubTree + ")" + to_string(curNode -> val) + + "(" + rightSubTree + ")";
        if (treeCount[curTree] == 1){
            result.push_back(curNode);
        }
        treeCount[curTree]++;
        return curTree;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> treeCount;
        vector<TreeNode*> result;

        findDuplicateSubtreesHelper(root, treeCount, result);
        return result;
    }
};