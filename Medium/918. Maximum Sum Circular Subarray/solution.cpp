class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int allNegetive = true;
        if (nums[0] >= 0)   allNegetive = false;
        int maxValue = nums[0];
        
        int totalSum = nums[0];
        
        int sum = nums[0];
        int minSubarray = nums[0];
        
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] < sum + nums[i]){
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
            minSubarray = min(sum, minSubarray);
            
            totalSum += nums[i];
            if (nums[i] >= 0)   allNegetive = false;
            maxValue = max(maxValue, nums[i]);
        }
        
        sum = nums[0];
        int maxSubarray = nums[0];
        
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] > sum + nums[i]){
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
            maxSubarray = max(sum, maxSubarray);
        }
        
        cout << totalSum << " " << maxSubarray << " " << minSubarray << endl;
        
        if (allNegetive)    return maxValue;
        
        return max(maxSubarray, totalSum - minSubarray);
    }
};