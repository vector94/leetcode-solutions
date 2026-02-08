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
    vector<int> v;
    vector<int> sum;
    void getVal(TreeNode *root){
        if (root == NULL){
            return;
        }
        v.push_back(root -> val);
        getVal(root -> left);
        getVal(root -> right);
    }
    void changeVal(TreeNode *root){
        if (root == NULL){
            return;
        }
        int idx = lower_bound(v.begin(), v.end(), root -> val) - v.begin();
        root -> val = sum[idx];
        changeVal(root -> left);
        changeVal(root -> right);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (root == NULL){
            return root;
        }
        getVal(root);
        sort(v.begin(), v.end());
        sum.push_back(v.back());
        for (int i = v.size() - 2; i >= 0; i--){
            sum.push_back(sum.back() + v[i]);
        }
        reverse(sum.begin(), sum.end());
        changeVal(root);
        return root;
    }
};