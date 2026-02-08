class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, bool> MP;
        for (int i = 0; i < min(k, (int)nums.size()); i++){
            if (MP[nums[i]]){
                return true;
            }
            MP[nums[i]] = true;
        }
        for (int i = k; i < nums.size(); i++){
            if (MP[nums[i]]){
                return true;
            }
            MP[nums[i]] = true;
            MP[nums[i - k]] = false;
        }
        return false;
    }
};