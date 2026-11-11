class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        long long min_num = INT_MAX;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            min_num = min(min_num, (long long)nums[i]);
        }
        return sum - min_num * (nums.size());
    }
};