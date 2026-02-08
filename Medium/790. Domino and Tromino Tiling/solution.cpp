class Solution {
public:
    int dp[2][2][1001];
    int mod = 1e9 + 7;
    
    int numTilingsHelper(int r1, int r2, int c, int n){
        if (c > n)  return 0;
        if (c == n){
            if (r1 == 0 && r2 == 0) return 1;
            return 0;
        }
        if (dp[r1][r2][c] != -1) return dp[r1][r2][c];
        
        int result = 0;
        
        if (r1 == 0 && r2 == 0){
            result += numTilingsHelper(0, 0, c + 1, n);
            result %= mod;
            result += numTilingsHelper(0, 0, c + 2, n);
            result %= mod;
            result += numTilingsHelper(1, 0, c + 1, n);
            result %= mod;
            result += numTilingsHelper(0, 1, c + 1, n);
            result %= mod;
        }
        
        else if (r1 == 1){
            result += numTilingsHelper(0, 1, c + 1, n);
            result %= mod;
            result += numTilingsHelper(0, 0, c + 2, n);
            result %= mod;
        }
        
        else if (r2 == 1){
            result += numTilingsHelper(1, 0, c + 1, n);
            result %= mod;
            result += numTilingsHelper(0, 0, c + 2, n);
            result %= mod;
        }
        
        return dp[r1][r2][c] = result;
    }
    
    int numTilings(int n) {
        memset(dp, -1, sizeof(dp));
        return numTilingsHelper(0, 0, 0, n);
    }
};