class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int arrSize = nums.size();
        for (int i = 0; i < arrSize - 1; i++){
            if (nums[i] == nums[i + 1]){
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int i, j;
        i = j = 0;

        while (j < arrSize){
            if (nums[j] > 0){
                nums[i] = nums[j];
                i++;
            }
            j++;
        }

        while (i < arrSize){
            nums[i] = 0;
            i++;
        }

        return nums;
    }
};