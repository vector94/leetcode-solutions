class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        long long ans = 0;

        for (int i = 0; i < nums.size(); i++){
            long long hiIdx = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            long long lowIdx = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();

            ans += (hiIdx - lowIdx);
        }

        return ans;
    }
};

// x -> fixed
// lower = x + y
// y = lower - x;