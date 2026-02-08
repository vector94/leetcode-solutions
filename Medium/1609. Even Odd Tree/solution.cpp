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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> myQueue;
        int level = 0;
        myQueue.push(root);
        
        while (!myQueue.empty()){
            vector<TreeNode*> curLevelNodes;
            
            while (!myQueue.empty()){
                curLevelNodes.push_back(myQueue.front());
                myQueue.pop();
            }
            
            cout << level << endl;
            
            for (int i = 0; i < curLevelNodes.size(); i++){
                cout << curLevelNodes[i] -> val << " ";
                if (level % 2 == 0){
                    if (curLevelNodes[i] -> val % 2 == 0 || (i != 0 && curLevelNodes[i] -> val <= curLevelNodes[i - 1] -> val)){
                        return false;
                    }
                }
                else{
                    if (curLevelNodes[i] -> val % 2 == 1 || (i != 0 && curLevelNodes[i] -> val >= curLevelNodes[i - 1] -> val)){
                        return false;
                    }
                }
                
                if (curLevelNodes[i] -> left != NULL){
                    myQueue.push(curLevelNodes[i] -> left);
                }
                if (curLevelNodes[i] -> right != NULL){
                    myQueue.push(curLevelNodes[i] -> right);
                }
            }
            level++;
            cout << endl;
        }
        return true;
    }
};