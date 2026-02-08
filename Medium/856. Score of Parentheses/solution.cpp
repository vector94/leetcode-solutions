class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> myStack;
        
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(')    myStack.push(0);
            else{
                int val = 0;
                while (myStack.top() != 0){
                    val += myStack.top();
                    myStack.pop();
                }
                val = max(2 * val, 1);
                myStack.pop();
                myStack.push(val);
            }
        }
        
        int result = 0;
        while (!myStack.empty()){
            result += myStack.top();
            myStack.pop();
        }
        
        return result;
    }
};