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
    int getTotalSum(TreeNode* root){
        if (root == NULL)   return 0;
        return root -> val + getTotalSum(root -> left) + getTotalSum(root -> right);
    }

    int findMaxProduct(TreeNode* root, int totalSum, long long &maxProd){
        if (root == NULL)   return 0;
        int curSum = root -> val + findMaxProduct(root -> left, totalSum, maxProd) +
                                            findMaxProduct(root -> right, totalSum, maxProd);
        maxProd = max(maxProd, (long long)curSum * (totalSum - curSum));
        cout << root -> val << " " << curSum << " " << totalSum << endl;
        return curSum;
    }

    int maxProduct(TreeNode* root) {
        long long maxProd = 0;
        findMaxProduct(root, getTotalSum(root), maxProd);
        return maxProd % 1000000007;
    }
};