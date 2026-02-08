class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> v;
        for (int x : nums){
            v.push_back(nums[x]);
        }
        return v;
    }
};