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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        getNodes(root, nodes);

        return genBalanceBST(0, nodes.size() - 1, nodes);
    }

    TreeNode* genBalanceBST(int left, int right, vector<int>& nodes){
        if (left > right)   return nullptr;
        if (left == right)  return new TreeNode(nodes[left]);

        int mid = (left + right) / 2;
        return new TreeNode(nodes[mid], genBalanceBST(left, mid - 1, nodes), genBalanceBST(mid + 1, right, nodes));
    }

    void getNodes(TreeNode* curNode, vector<int>& nodes){
        if (curNode == NULL)    return;
        
        getNodes(curNode -> left, nodes);
        
        nodes.push_back(curNode -> val);
        
        getNodes(curNode -> right, nodes);
    }
};