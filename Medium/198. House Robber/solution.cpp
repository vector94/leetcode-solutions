class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = 0;
        int prev2 = nums[0];
        for (int i = 1; i < n; i++){
            int current = max(prev1 + nums[i], prev2);
            prev1 = prev2;
            prev2 = current;
        }
        
        return prev2;
    }
};