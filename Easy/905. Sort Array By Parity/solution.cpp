class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ret(nums.size());
        int i = 0;
        int j = nums.size() - 1;
        for (int k = 0; k < nums.size(); k++){
            if (nums[k] & 1){
                ret[j--] = nums[k];
            }
            else{
                ret[i++] = nums[k];
            }
        }
        return ret;
    }
};