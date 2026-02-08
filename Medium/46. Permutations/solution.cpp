class Solution {
public:
    
    void backtrack(vector<int> &nums, int mask, vector<int> &p, vector<vector<int>> &result){
        if (p.size() == nums.size()){
            result.push_back(p);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (mask & (1 << i)){
                continue;
            }
            mask |= (1 << i);
            p.push_back(nums[i]);
            backtrack(nums, mask, p, result);
            mask &= ~(1 << i);
            p.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> p;
        vector<vector<int> > result;
        backtrack(nums, 0, p, result);
        return result;
    }
};