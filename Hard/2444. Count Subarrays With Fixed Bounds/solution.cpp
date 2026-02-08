class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minIdx, maxIdx, badIdx;
        minIdx = maxIdx = badIdx = -1;
        int N = nums.size();
        long long ans = 0;

        for (int i = 0; i < N; i++){
            if (nums[i] == minK){
                minIdx = i;
            }
            if (nums[i] == maxK){
                maxIdx = i;
            }
            if (nums[i] < minK || nums[i] > maxK){
                badIdx = i;
            }

            long long cnt = min(minIdx, maxIdx) - badIdx;
            ans += cnt > 0 ? cnt : 0;
        }

        return ans;
    }
};