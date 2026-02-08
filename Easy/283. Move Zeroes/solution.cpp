class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++){
            if (nums[j] != 0){
                nums[i] = nums[j];
                i++;
            }
            else{
                zeros++;
            }
        }
        for (int i = nums.size() - 1, k = 0; i >= 0 && k < zeros; i--, k++){
            nums[i] = 0;
        }
    }
};