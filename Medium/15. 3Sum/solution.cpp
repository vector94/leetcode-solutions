class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        set<int> set1;
        for (int i = 0; i < nums.size(); i++){
            if (set1.find(nums[i]) != set1.end()){
                continue;
            }
            set1.insert(nums[i]);
            set<int> set2;
            for (int j = i + 1; j < nums.size(); j++){
                if (set2.find(nums[j]) != set2.end()){
                    continue;
                }
                set2.insert(nums[j]);
                int x = nums[i] + nums[j];
                int idx = lower_bound(nums.begin() + j + 1, nums.end(), -x) - nums.begin();
                if (idx == nums.size() || nums[idx] != -x){
                    continue;
                }
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[j]);
                v.push_back(nums[idx]);
                ret.push_back(v);
            }
        }
        return ret;
    }
};