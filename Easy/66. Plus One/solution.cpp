class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int> myStack;
        int curSum = digits.back() + 1;
        myStack.push(curSum % 10);
        curSum /= 10;

        for (int i = digits.size() - 2; i >= 0; i--){
            curSum += digits[i];
            myStack.push(curSum % 10);
            curSum /= 10;
        }
        
        if (curSum > 0){
            myStack.push(curSum);
        }

        vector<int> result;

        while (!myStack.empty()){
            result.push_back(myStack.top());
            myStack.pop();
        }

        return result;
    }
};