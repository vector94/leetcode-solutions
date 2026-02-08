class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prevOnePos = -1e7;
        int zeroCnt = 0;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 1){
                if (i - prevOnePos <= k){
                    return false;
                }
 
                prevOnePos = i;
            }
        }

        return true;
    }
};