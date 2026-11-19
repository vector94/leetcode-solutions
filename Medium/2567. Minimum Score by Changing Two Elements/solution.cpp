class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int len = nums.size();

        int x = nums[len - 1] - nums[2];
        int y = nums[len - 3] - nums[0];
        int z = nums[len - 2] - nums[1];

        return min({x, y, z});
    }
};