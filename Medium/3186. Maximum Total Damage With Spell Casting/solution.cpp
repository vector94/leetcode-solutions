class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        sort(power.begin(), power.end());
        
        vector<long long> dp(n, -1);
        unordered_map<int, int> powerCnt;

        for (int p : power){
            powerCnt[p]++;
        }

        return solve(0, power, powerCnt, dp);
    }

    long long solve(int idx, vector<int>& power, unordered_map<int, int>& powerCnt, vector<long long>& dp){
        if (idx >= power.size())    return 0;

        if (dp[idx] != -1)  return dp[idx];

        long long ret1 = solve(idx + 1, power, powerCnt, dp);
        
        int nextIdx = lower_bound(begin(power) + idx + 1, end(power), power[idx] + 3) - begin(power);
        
        long long ret2 = 1LL * power[idx] * powerCnt[power[idx]] + solve(nextIdx, power, powerCnt, dp);
        
        return dp[idx] = max(ret1, ret2);
    }
};