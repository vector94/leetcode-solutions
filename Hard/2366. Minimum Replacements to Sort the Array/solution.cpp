class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--){
            if (nums[i] <= nums[i + 1]){
                continue;
            }

            int split_count = (nums[i] + (nums[i + 1] - 1)) / nums[i + 1];
            ans += split_count - 1;
            nums[i] /= split_count;
        }

        return ans;
    }
};