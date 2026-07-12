class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        vector<int> result(N);

        stack<int> myStack;

        for (int i = 0; i < temperatures.size(); i++){
            while (!myStack.empty() && temperatures[myStack.top()] < temperatures[i]){
                int idx = myStack.top();
                myStack.pop();
                result[idx] = i - idx;
            }

            myStack.push(i);
        }

        while (!myStack.empty()){
            result[myStack.top()] = 0;
            myStack.pop();
        }

        return result;
    }
};