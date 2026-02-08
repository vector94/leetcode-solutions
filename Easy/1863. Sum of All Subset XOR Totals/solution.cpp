class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return solve(0, nums, 0);      
    }

    int solve(int i, vector<int>& nums, int curXor){
        if (i == nums.size())   return curXor;

        return solve(i + 1, nums, nums[i] ^ curXor) + solve(i + 1, nums, curXor);
    }
};