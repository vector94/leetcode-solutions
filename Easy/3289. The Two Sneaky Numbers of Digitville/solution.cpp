class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> result;
        vector<int> freq(101, 0);

        for (int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
            if (freq[nums[i]] > 1){
                result.push_back(nums[i]);
            }
        }

        return result;
    }
};