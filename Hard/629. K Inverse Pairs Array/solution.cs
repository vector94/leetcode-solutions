public class Solution {
    private const int _mod = 1000000007;
    public int KInversePairs(int n, int k) {
        int[,] dp = new int[n + 1, k + 1];

        // InitDP(n, k, dp);
        // return KInversePairsHelper(n, k, dp);

        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= k; j++){
                if (j == 0){
                    dp[i, j] = 1;
                }
                else{
                    for (int p = 0; p <= Math.Min(j, i - 1); p++){
                        dp[i, j] = (dp[i, j] + dp[i - 1, j - p]) % _mod;
                    }
                }
            }
        }

        return dp[n, k];
    }

    // private int KInversePairsHelper(int n, int k, int[,] dp){
    //     if (n == 0){
    //         return 0;
    //     }
    //     if (k == 0){
    //         return 1;
    //     }
    //     if (dp[n, k] != -1){
    //         return dp[n, k];
    //     }

    //     long result = 0;
    //     for (int i = 0; i <= Math.Min(k, n - 1); i++){
    //         result += KInversePairsHelper(n - 1, k - i, dp);
    //         result %= _mod;
    //     }
    //     return dp[n, k] = (int)result;
    // }

    // private void InitDP(int n, int k, int[,] dp){
    //     for (int i = 0; i <= n; i++){
    //         for (int j = 0; j <= k; j++){
    //             dp[i, j] = -1;
    //         }
    //     }
    // }
}