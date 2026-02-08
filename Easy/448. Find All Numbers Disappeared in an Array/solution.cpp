class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()){
            if (nums[i] - 1 == i || nums[nums[i] - 1] == nums[i]){
                i++;
                continue;
            }
            swap(nums[i], nums[nums[i] - 1]);
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] - 1 != i){
                result.push_back(i + 1);
            }
        }
        return result;
    }
};