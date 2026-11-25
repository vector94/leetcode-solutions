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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        vector<vector<TreeNode*>> paths;
        
        queue<vector<TreeNode*>> myQueue;

        vector<TreeNode*> curPath;
        curPath.push_back(root);

        myQueue.push(curPath);

        while (!myQueue.empty()){
            curPath = myQueue.front();
            myQueue.pop();

            TreeNode* curNode = curPath.back();
            if (curNode -> left == NULL && curNode -> right == NULL){
                paths.push_back(curPath);
                continue;
            }

            if (curNode -> left != NULL){
                vector<TreeNode*> newPath = curPath;
                newPath.push_back(curNode -> left);
                myQueue.push(newPath);
            }
            if (curNode -> right != NULL){
                vector<TreeNode*> newPath = curPath;
                newPath.push_back(curNode -> right);
                myQueue.push(newPath);
            }
        }
        
        for (int i = 0; i < paths.size(); i++){
            string path = "";
            for (int j = 0; j < paths[i].size(); j++){
                TreeNode* curNode = paths[i][j];
                path += to_string(curNode -> val);
                if (j != paths[i].size() - 1){
                    path += "->";
                }
            } 

            results.push_back(path);
        }

        return results;
    }
};