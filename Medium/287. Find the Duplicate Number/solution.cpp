class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] - 1 == i)   continue;
            if (nums[i] == nums[nums[i] - 1]){
                return nums[i];
            }
            swap(nums[i], nums[nums[i] - 1]);
            i--;
        }
        return 0;
    }
};