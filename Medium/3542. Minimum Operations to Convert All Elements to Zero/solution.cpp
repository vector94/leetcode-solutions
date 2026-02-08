class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> myStack;

        int ans = 0;

        for (int n : nums){
            while (!myStack.empty() && n < myStack.top()){
                myStack.pop();
            }

            if (n == 0) continue;

            if (myStack.empty() || n > myStack.top()){
                myStack.push(n);
                ans++;
            }
        }

        return ans;
    }
};