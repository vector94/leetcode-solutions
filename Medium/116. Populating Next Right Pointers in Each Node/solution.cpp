/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if (root == NULL)   return root;
        
        queue<Node*> Q;
        Q.push(root);
        
        while (!Q.empty()){
            int levelSize = Q.size();
            
            for (int i = 1; i <= levelSize; i++){
                Node* curNode = Q.front();
                Q.pop();
                
                if (i == levelSize){
                    curNode -> next = NULL;    
                }
                else{
                    curNode -> next = Q.front();
                }
                
                if (curNode -> left != NULL){
                    Q.push(curNode -> left);
                    Q.push(curNode -> right);
                }
            }
        }
        
        return root;
        
    }
};