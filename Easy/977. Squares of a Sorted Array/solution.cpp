class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret(nums.size());
        int i = 0;
        int j = nums.size() - 1;
        int k = nums.size() - 1;
        while (i <= j){
            if (abs(nums[i]) > abs(nums[j])){
                ret[k] = nums[i] * nums[i];
                i++;
            }
            else{
                ret[k] = nums[j] * nums[j];
                j--;
            }
            k--;
        }
        return ret;
    }
};