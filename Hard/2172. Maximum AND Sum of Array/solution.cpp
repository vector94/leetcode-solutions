class Solution {
public:
    
    int Set(int mask, int bit){
        return mask | (1 << bit);
    }
    int Reset(int mask, int bit){
        return mask & ~(1 << bit);
    }
    bool Check(int mask, int bit){
        return (bool) (mask & (1 << bit));
    }
    
    int dp[1025][1025][20];
    
    int maximumANDSumHelper(int index, int mask1, int mask2, vector<int> &nums, int numSlots){
        if (index == nums.size())   return 0;
        
        if (dp[mask1][mask2][index] != -1)  return dp[mask1][mask2][index];
        
        int result = 0;
        
        for (int i = 1; i <= numSlots; i++){
            if (!Check(mask1, i)){
                result = max(result, (nums[index] & i) + maximumANDSumHelper(index + 1, Set(mask1, i), mask2, nums, numSlots));
            }
            else if (!Check(mask2, i)){
                result = max(result, (nums[index] & i) + maximumANDSumHelper(index + 1, mask1, Set(mask2, i), nums, numSlots));
            }
        }
        
        return dp[mask1][mask2][index] = result;
    }
    
    int maximumANDSum(vector<int>& nums, int numSlots) {
        memset(dp, -1, sizeof(dp));
        
        return maximumANDSumHelper(0, 0, 0, nums, numSlots);
    }
};