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
    vector<int> graph[100005];
    int amountOfTime(TreeNode* root, int start) {
        queue<pair<TreeNode*, int>> myQueue;
        TreeNode* startNode = NULL;

        myQueue.push({root, -1});
        while (!myQueue.empty()){
            TreeNode* curNode = myQueue.front().first;
            int parent = myQueue.front().second;
            myQueue.pop();

            if (parent != -1){
                graph[curNode -> val].push_back(parent);
                graph[parent].push_back(curNode -> val);
            }

            if (curNode -> left != NULL){
                myQueue.push({curNode -> left, curNode -> val});
            }
            if (curNode -> right != NULL){
                myQueue.push({curNode -> right, curNode -> val});
            }
        }

        return maxDepth(start, -1);
    }

    int maxDepth(int curNode, int parentNode){
        int curMax = 0;
        for (int nextNode : graph[curNode]){
            if (nextNode != parentNode){
                curMax = max(curMax, 1 + maxDepth(nextNode, curNode));
            }
        }
        return curMax;
    }
};