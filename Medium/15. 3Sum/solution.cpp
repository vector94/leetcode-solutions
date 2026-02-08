class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        if (nums.size() < 3)    return result;
        
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++){
            if (i > 0 && nums[i] == nums[i - 1])    continue;
            int need = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right){
                if (left > i + 1 && nums[left] == nums[left - 1])   left++;
                else if (right < nums.size() - 1 && nums[right] == nums[right + 1]) right--;
                else if (nums[left] + nums[right] == need){
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                }
                else if (nums[left] + nums[right] < need){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        
        return result;
    }
};