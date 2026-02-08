class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = nums.size() + 1;
        int left = 0;
        int sum = 0;
        
        for (int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while (sum >= target){
                result = min(result, right - left + 1);
                sum -= nums[left++];
            }
        }
        
        if (result == nums.size() + 1)  return 0;
        return result;
    }
};