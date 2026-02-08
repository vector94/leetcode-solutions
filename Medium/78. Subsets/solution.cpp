class Solution {
public:
    
    void backtrack(int index, vector<int> &nums, vector<int> &v, vector<vector<int>> &result){
        if (index == nums.size()){
            result.push_back(v);
            return;
        }
        
        v.push_back(nums[index]);
        backtrack(index + 1, nums, v, result);
        v.pop_back();
        
        backtrack(index + 1, nums, v, result);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> v;
        
        backtrack(0, nums, v, result);
        return result;
    }
};