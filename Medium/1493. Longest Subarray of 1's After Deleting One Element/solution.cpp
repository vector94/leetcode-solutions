class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int preCnt = 0;

        for (int i = 0; i < nums.size(); i++){
            int zeroCnt = 0;

            while (i < nums.size() && nums[i] == 0){
                zeroCnt++;
                i++;
            }

            int oneCnt = 0;
            while (i < nums.size() && nums[i] == 1){
                oneCnt++;
                i++;
            }
            i--;

            if (zeroCnt == 1){
                ans = max(ans, preCnt + oneCnt);
            }
            else if (zeroCnt == 0){
                ans = max({ans, oneCnt - 1, preCnt - 1});
            }
            else{
                ans = max({ans, oneCnt, preCnt});
            }

            preCnt = oneCnt;
        }

        return ans;
    }
};