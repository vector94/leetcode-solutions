class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> prefixSum;
        prefixSum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++){
            prefixSum.push_back(prefixSum.back() + nums[i]);
        }
        long long minDiffAvg = LLONG_MAX;
        int minIndex = 0;
        for (int i = 0; i < nums.size(); i++){
            long long leftAvg = prefixSum[i] / (i + 1);
            long long rightAvg = i == nums.size() - 1 ? 0 : (prefixSum[nums.size() - 1] - prefixSum[i]) / (nums.size() - i - 1);
            if (minDiffAvg > abs(leftAvg - rightAvg)){
                minIndex = i;
                minDiffAvg = abs(leftAvg - rightAvg);
            }
        }
        return minIndex;
    }
};