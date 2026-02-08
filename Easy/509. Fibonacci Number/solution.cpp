class Solution {
public:
    
    int fibHelper(int n, vector<int> &dp){
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        if (dp[n] != -1)    return dp[n];
        
        int ret = fibHelper(n - 1, dp) + fibHelper(n - 2, dp);
        return dp[n] = ret;
    }
    
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return fibHelper(n, dp);
    }
};