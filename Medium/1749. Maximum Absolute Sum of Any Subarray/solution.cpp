class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minPrefixSum, maxPrefixSum, curSum;
        minPrefixSum = maxPrefixSum = curSum = 0;

        int ans = 0;
        for (int i = 0; i < nums.size(); i++){
            minPrefixSum = min(minPrefixSum, curSum);
            maxPrefixSum = max(maxPrefixSum, curSum);

            curSum += nums[i];
            ans = max({ans, abs(curSum - minPrefixSum), abs(curSum - maxPrefixSum)});
        }

        return ans;
    }
};