class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        unordered_map<int, bool> inStack;
        stack<int> myStack;
        int j = 0;
        for (int i = 0; i < popped.size(); i++){
            if (!inStack[popped[i]]){
                while (!inStack[popped[i]]){
                    inStack[pushed[j]] = true;
                    myStack.push(pushed[j]);
                    j++;
                }
                myStack.pop();
            }
            else{
                if (myStack.top() == popped[i]){
                    myStack.pop();
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};