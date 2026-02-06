class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for (int n : nums){
            sum += n;
        }

        int ans = 0;
        int curSum = 0;
        for (int i = 0; i < nums.size() - 1; i++){
            if ((curSum - (sum - curSum)) % 2 == 0){
                ans++;
            }
        }

        return ans;
    }
};