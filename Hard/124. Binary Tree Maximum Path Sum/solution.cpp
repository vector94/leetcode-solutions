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
    
    void dfs1(TreeNode* curNode, int &totalNode, unordered_map<TreeNode*, int> &nodeID){
        if (curNode == NULL)    return;
        
        nodeID[curNode] = totalNode;
        // cout << curNode -> val << ", " << totalNode << endl;
        totalNode++;
        
        dfs1(curNode -> left, totalNode, nodeID);
        dfs1(curNode -> right, totalNode, nodeID);
        
    }
    
    int dfs2(TreeNode* curNode, unordered_map<TreeNode*, int> &nodeID, vector<int> &leftSum, vector<int> &rightSum){
        if (curNode == NULL)   return 0;
        
        int lsum = dfs2(curNode -> left, nodeID, leftSum, rightSum);
        int rsum = dfs2(curNode -> right, nodeID, leftSum, rightSum);
        
        int curID = nodeID[curNode];
        
        // cout << curID << ", " << lsum << ", " << rsum << endl;
        
        leftSum[curID] = lsum;
        rightSum[curID] = rsum;
        
        return max(curNode -> val, curNode -> val + max(lsum, rsum));
    }
    
    void dfs3(TreeNode* curNode, int parentSum, unordered_map<TreeNode*, int> &nodeID, vector<int> &leftSum, vector<int> &rightSum, int &result){
        if (curNode == NULL)    return;
        
        int curID = nodeID[curNode];
        
        result = max({result, curNode -> val, curNode -> val + max({leftSum[curID], rightSum[curID], parentSum, leftSum[curID] + rightSum[curID], 
                                                   leftSum[curID] + parentSum, rightSum[curID] + parentSum})});
        
        dfs3(curNode -> left, max({curNode -> val, curNode -> val + parentSum, curNode -> val + rightSum[curID]}), nodeID, leftSum, rightSum, result);
        dfs3(curNode -> right, max({curNode -> val, curNode -> val + parentSum, curNode -> val + leftSum[curID]}), nodeID, leftSum, rightSum, result);
    }

    
    int maxPathSum(TreeNode* root) {
        
        int totalNode = 0;
        unordered_map<TreeNode*, int> nodeID;
        
        dfs1(root, totalNode, nodeID);
        
        vector<int> leftSum(totalNode, 0);
        vector<int> rightSum(totalNode, 0);
        
        dfs2(root, nodeID, leftSum, rightSum);
        
        int result = root -> val;
        dfs3(root, 0, nodeID, leftSum, rightSum, result);
        
        return result;
        
    }
};