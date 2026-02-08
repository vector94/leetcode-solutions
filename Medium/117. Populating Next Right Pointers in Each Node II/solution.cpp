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
        Node* nextHead = new Node();
        Node* preNode = nextHead;
        
        Node* curNode = root;
        while (curNode){
            while (curNode){
                if (curNode -> left){
                    preNode -> next = curNode -> left;
                    preNode = preNode -> next;
                }
                if (curNode -> right){
                    preNode -> next = curNode -> right;
                    preNode = preNode -> next;
                }
                curNode = curNode -> next;
            }
            curNode = nextHead -> next;
            nextHead = new Node();
            preNode = nextHead;
        }
        
        return root;
    }
};