class Solution {
public:
    
    void backtrack(int curIndex, vector<int> &nums, int &curXor, int &total){
        total += curXor;
        if (curIndex == nums.size()){
            return;
        }
        for (int i = curIndex; i < nums.size(); i++){
            curXor ^= nums[i];
            backtrack(i + 1, nums, curXor, total);
            curXor ^= nums[i];
        }
    }
    
    int subsetXORSum(vector<int>& nums) {
        int total, curXor;
        total = curXor = 0;
        backtrack(0, nums, curXor, total);
        return total;
    }
};