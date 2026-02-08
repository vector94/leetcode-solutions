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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ret;
        if (root == NULL){
            return ret;
        }
        vector<TreeNode*> v1;
        v1.push_back(root);
        while (!v1.empty()){
            vector<TreeNode*> v2;
            vector<int> node;
            for (auto x : v1){
                node.push_back(x -> val);
                if (x -> left){
                    v2.push_back(x -> left);
                }
                if (x -> right){
                    v2.push_back(x -> right);
                }
            }
            ret.push_back(node);
            v1 = v2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};