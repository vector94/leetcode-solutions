class Solution {
public:
    int mod = 1e9 + 7;
    long long countHelper(int p, int d, int n, vector<vector<int> > &dp){
        if (p == n && d == n)           return 1;
        if (d > p || p > n || d > n)    return 0;
        if (dp[p][d] != -1)             return dp[p][d];
        
        long long ret = (n - p) * countHelper(p + 1, d, n, dp);
        ret %= mod;

        ret += (p - d) * countHelper(p, d + 1, n, dp);
        ret %= mod;
        
        return dp[p][d] = ret;
    }
    
    int countOrders(int n) {
        vector<vector<int> > dp(n + 1, vector<int> (n + 1, -1));
        return countHelper(0, 0, n, dp);
    }
};