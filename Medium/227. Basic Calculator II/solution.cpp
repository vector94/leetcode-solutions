class Solution {
public:
    
    bool isDigit(char ch){
        return ch >= '0' && ch <= '9';
    }
    
    int calculate(string s) {
        stack<int> myStack;
        
        int curNum = 0;
        char operation = '+';
        
        for (int i = 0; i < s.size(); i++){
            if (isDigit(s[i])){
                curNum *= 10;
                curNum += (s[i] - '0');
            }
            if (!isDigit(s[i]) && s[i] != ' ' || i == s.size() - 1){
                if (operation == '+'){
                    myStack.push(curNum);
                }
                else if (operation == '-'){
                    myStack.push(-curNum);
                }
                else if (operation == '*'){
                    int preNum = myStack.top();
                    myStack.pop();
                    myStack.push(preNum * curNum);
                }
                else{
                    int preNum = myStack.top();
                    myStack.pop();
                    myStack.push(preNum / curNum);
                }
                operation = s[i];
                curNum = 0;
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