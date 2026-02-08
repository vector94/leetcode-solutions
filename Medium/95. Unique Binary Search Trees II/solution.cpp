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
    
    vector<TreeNode*> genTrees(int start, int end){
        vector<TreeNode*> curList;
        
        if (start > end){
            curList.push_back(NULL);
            return curList;
        }
        if (start == end){
            curList.push_back(new TreeNode(start));
            return curList;
        }
        
        for (int curVal = start; curVal <= end; curVal++){
            
            vector<TreeNode*> leftTree, rightTree;
            leftTree = genTrees(start, curVal - 1);
            rightTree = genTrees(curVal + 1, end);
            
            for (int i = 0; i < leftTree.size(); i++){
                for (int j = 0; j < rightTree.size(); j++){
                    
                    TreeNode *curNode = new TreeNode(curVal);
                    
                    curNode -> left = leftTree[i];
                    curNode -> right = rightTree[j];
                    
                    curList.push_back(curNode);                   
                }
            }
        }
        return curList;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return genTrees(1, n);
    }
};