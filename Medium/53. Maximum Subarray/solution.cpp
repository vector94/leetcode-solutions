class Solution {
public:
    long long int maxSubArray(vector<int>& nums) {
        long long int ret = LONG_LONG_MIN;
        long long int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > sum + nums[i]){
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
            ret = max(ret, sum);
        }
        return ret;
    }
};