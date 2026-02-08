class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int len = nums.size();
        int ans = 1;

        for (int i = 0; i < len; i++){
            int curLen = 1;
            int j = i + 1;
            while (j < len && nums[j - 1] < nums[j]){
                j++;
                curLen++;
            }
            ans = max(ans, curLen);
        }

        for (int i = 0; i < len; i++){
            int curLen = 1;
            int j = i + 1;
            while (j < len && nums[j - 1] > nums[j]){
                j++;
                curLen++;
            }
            ans = max(ans, curLen);
        }

        return ans;
    }
};