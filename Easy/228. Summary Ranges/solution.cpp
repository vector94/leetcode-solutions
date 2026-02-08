class Solution {
public:
    
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.size() == 0)   return result;
        int left = nums[0];
        for (int i = 0; i < nums.size(); i++){
            if (i == nums.size() - 1 || nums[i] != nums[i + 1] - 1){
                string cur = "";
                if (left == nums[i]){
                    cur += to_string(left);
                }
                else{
                    cur += to_string(left);
                    cur += "->";
                    cur += to_string(nums[i]);
                }
                result.push_back(cur);
                if (i != nums.size() - 1)   left = nums[i + 1];
            }
        }
        return result;
    }
};