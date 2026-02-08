class Solution {
public:
    
    int Set(int mask, int bit){
        return mask | (1 << bit);
    }
    
    bool Check(int mask, int bit){
        return (bool) (mask & (1 << bit));
    }
    
    bool Reset(int mask, int bit){
        return (mask & ~(1 << bit));
    }
    
    void backtrack(int mask, vector<int> &nums, vector<int> &v, vector<vector<int> > &result){
        if (__builtin_popcount(mask) == nums.size()){
            result.push_back(v);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1] && !Check(mask, i - 1) || Check(mask, i)){
                continue;
            }
            v.push_back(nums[i]);
            backtrack(Set(mask, i), nums, v, result);
            v.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> v;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, v, result);
        
        return result;
    }
};