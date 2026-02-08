class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int N = nums.size();
        vector<long long> prefixMax(N), suffixMax(N);

        prefixMax[0] = nums[0];
        for (int i = 1; i < N; i++){
            prefixMax[i] = max(prefixMax[i - 1], (long long)nums[i]);
        }

        suffixMax[N - 1] = nums[N - 1];
        for (int i = N - 2; i >= 0; i--){
            suffixMax[i] = max(suffixMax[i + 1], (long long)nums[i]);
        }

        long long ans = 0;
        for (int j = 1; j < N - 1; j++){
            ans = max(ans, (prefixMax[j - 1] - nums[j]) * suffixMax[j + 1]);
        }

        return ans;
    }
};