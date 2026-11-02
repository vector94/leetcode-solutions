class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sz = nums.size();
        
        sort(nums.begin(), nums.end());
        int med = nums[sz / 2];

        int ans = 0;
        for (int n : nums){
            ans += abs(med - n);
        }

        return ans;
    }
};