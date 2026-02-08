class Solution {
public:
    vector<vector<int>> ret;
    void solve(vector<int> &nums, int idx, vector<int> &v){
        ret.push_back(v);
        for (int i = idx; i < nums.size(); i++){
            v.push_back(nums[i]);
            solve(nums, i + 1, v);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        solve(nums, 0, v);
        return ret;
    }
};