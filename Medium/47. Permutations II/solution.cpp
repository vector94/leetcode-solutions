class Solution {
public:
    
    int Set(int num, int bit){
        return num | (1 << bit);
    }
    int Reset(int num, int bit){
        return num & ~(1 << bit);
    }
    bool Check(int num, int bit){
        return (bool) (num & (1 << bit));
    }
    
    void backtrack(int mask, vector<int> &nums, vector<int> &p, vector<vector<int> > &result){
 
        if (p.size() == nums.size()){
            result.push_back(p);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1] && !Check(mask, i - 1) || Check(mask, i)){
                continue;
            }
            mask = Set(mask, i);
            p.push_back(nums[i]);
            backtrack(mask, nums, p, result);
            p.pop_back();
            mask = Reset(mask, i);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> p;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, p, result);
        return result;
    }
};