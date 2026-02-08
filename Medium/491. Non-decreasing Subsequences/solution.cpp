class Solution {
public:
    
    void backtrack(int start, vector<int> &nums, vector<int> &v, vector<vector<int> > &result){
        if (v.size() >= 2){
            result.push_back(v);
        }
        if (start == nums.size()){
            return;
        }
        unordered_set<int> seen;
        for (int i = start; i < nums.size(); i++){
            
            if ((v.empty() || v.back() <= nums[i]) && seen.find(nums[i]) == seen.end()){
                v.push_back(nums[i]);
                backtrack(i + 1, nums, v, result);
                v.pop_back();
                seen.insert(nums[i]);
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> v;
        backtrack(0, nums, v, result);
        return result;
    }
};