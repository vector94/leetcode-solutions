class Solution {
public:
    int minOperations(vector<int>& nums) {
        int oneCnt = 0;

        for (int n : nums){
            if (n == 1) oneCnt++;
        }

        if (oneCnt > 0) return nums.size() - oneCnt;

        int ans = INT_MAX;
        for (int i = 0; i < nums.size() - 1; i++){
            int gcd = nums[i];
            
            for (int j = i + 1; j < nums.size(); j++){
                gcd = __gcd(nums[j], gcd);
                if (gcd == 1){
                    cout << i << " " << j << endl;
                    ans = min(ans, (int)nums.size() + (j - i) - 1);
                    break;
                }
            }
        }

        if (ans == INT_MAX) return -1;
        return ans;
    }
};