class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> myStack;
        for (string op : ops){
            if (op == "+"){
                int x = myStack.top();
                myStack.pop();
                int y = myStack.top();
                myStack.pop();
                myStack.push(y);
                myStack.push(x);
                myStack.push(x + y);
            }
            else if (op == "D"){
                int x = myStack.top();
                myStack.push(x * 2);
            }
            else if (op == "C"){
                myStack.pop();
            }
            else{
                myStack.push(stoi(op));
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