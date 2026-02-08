class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const int MOD = 1e9 + 7;
        vector<vector<long long>> count(15, vector<long long>(10005, 0));
        vector<vector<long long>> prefixSum(15, vector<long long>(10005, 0));
        vector<long long> options(15, 0);
        
        for (int i = 1; i <= 10000; i++) {
            count[1][i] = 1;
            prefixSum[1][i] = i;
        }
        
        for (int i = 2; i <= 14; i++) {
            for (int j = i; j <= 10000; j++) {
                count[i][j] = prefixSum[i - 1][j - 1];
                prefixSum[i][j] = count[i][j] + prefixSum[i][j - 1];
                count[i][j] %= MOD;
                prefixSum[i][j] %= MOD;
            }
        }
        
        for (int i = 1; i <= maxValue; i++) {
            countUniqueSequences(i, 1, maxValue, options);
        }
        
        long long ans = 0;
        for (int i = 1; i <= 14; i++) {
            long long ways = count[i][n] * options[i];
            ways %= MOD;
            ans += ways;
            ans %= MOD;
        }
        return ans;
    }
    
private:
    void countUniqueSequences(int curr, int idx, int maxValue, vector<long long>& options) {
        options[idx] += 1;
        for (int j = 2; curr * j <= maxValue; j++) {
            countUniqueSequences(curr * j, idx + 1, maxValue, options);
        }
    }
};