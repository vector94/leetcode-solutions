class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> myStack;
        int curMin = nums[0];
        
        for (int num : nums){
            while (!myStack.empty() && myStack.top().first <= num){
                myStack.pop();
            }
            
            if (!myStack.empty() && num > myStack.top().second){ 
                return true;
            }
            myStack.push({num, curMin});
            curMin = min(curMin, num);
        }
        
        return false;
    }
};
