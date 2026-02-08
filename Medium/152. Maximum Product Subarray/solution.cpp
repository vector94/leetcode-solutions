class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        
        for (int i = 0; i < nums.size(); i++){
            result = max(result, nums[i]);
        }
        
        int curMin, curMax;
        curMin = curMax = 1;
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                curMin = curMax = 1;
                continue;
            }
            
            int temp = curMax;
            curMax = max({curMax * nums[i], curMin * nums[i], nums[i]});
            curMin = min({temp * nums[i], curMin * nums[i], nums[i]});
            
            result = max(result, curMax);
        }
        
        return result;
    }
};