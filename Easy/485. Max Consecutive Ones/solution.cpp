class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int curCnt = 0;

        for (int n : nums){
            if (n == 1){
                curCnt++;
                ans = max(ans, curCnt);
            }
            else{
                curCnt = 0;
            }
        }

        return ans;
    }
};