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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr){
            return ret;
        }
        vector<TreeNode*> v;
        v.push_back(root);
        while (!v.empty()){
            ret.push_back(v[0] -> val);
            vector<TreeNode*> temp;
            for (auto cur : v){
                if (cur -> right != nullptr){
                    temp.push_back(cur -> right);
                }
                if (cur -> left != nullptr){
                    temp.push_back(cur -> left);
                }
            }
            v = temp;
        }
        return ret;
    }
};
