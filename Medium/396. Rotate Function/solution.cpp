class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int f0 = 0;

        for (int i = 0; i < n; i++){
            sum += nums[i];
            f0 += i * nums[i];
        }

        int result = f0;
        int prev = f0;

        for (int i = 1; i < n; i++){
            int f = prev + sum - n * nums[n - i];
            result = max(result, f);
            prev = f;
        }

        return result;
    }
};