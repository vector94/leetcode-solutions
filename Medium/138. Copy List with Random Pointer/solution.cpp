/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> myMap;
        
        Node* curNode = head;
        while (curNode){
            Node* copy = new Node(curNode -> val);
            myMap[curNode] = copy;
            curNode = curNode -> next;
        }
        
        curNode = head;
        while (curNode){
            Node* copy = myMap[curNode];
            copy -> next = myMap[curNode -> next];
            copy -> random = myMap[curNode -> random]; 
            curNode = curNode -> next; 
        }
        
        return myMap[head];
    }
};