class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        long long res = (nums[len - 1] * nums[len - 2]) - (nums[0] * nums[1]);
        return res;
    }
};