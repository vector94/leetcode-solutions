class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int curSum = 0;
        for (int i = 0; i < nums.size(); i++){
            if (i == 0 || nums[i] <= nums[i - 1]){
                ans = max(ans, curSum);
                curSum = nums[i];
            }
            else{
                curSum += nums[i];
            }
        }

        ans = max(ans, curSum);
        return ans;
    }
};