class Solution {
public:
    long long dp[2][2][1005];
    int mod = 1e9 + 7;
    
    int numTilings(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, n);
    }

    int solve(int r1, int r2, int c, int n){
        if (c > n)  return 0;
        if (c == n){
            if (r1 == 0 && r2 == 0){
                return 1;
            }
            return 0;
        }
        
        if (dp[r1][r2][c] != -1)    return dp[r1][r2][c];

        long long result = 0;

        if (r1 == 0 && r2 == 0){
            result += solve(0, 0, c + 1, n);
            result %= mod;
            result += solve(0, 0, c + 2, n);
            result %= mod;
            result += solve(1, 0, c + 1, n);
            result %= mod;
            result += solve(0, 1, c + 1, n);
            result %= mod;
        }
        else if (r1 == 1){
            result += solve(0, 0, c + 2, n);
            result %= mod;
            result += solve(0, 1, c + 1, n);
            result %= mod;
        }
        else{
            result += solve(0, 0, c + 2, n);
            result %= mod;
            result += solve(1, 0, c + 1, n);
            result %= mod;
        }

        return dp[r1][r2][c] = result;
    }
};