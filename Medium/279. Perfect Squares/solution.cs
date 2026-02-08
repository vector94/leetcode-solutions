public class Solution {
    public int NumSquares(int n) {
        int[] dp = new int[n + 1];
        
        InitDP(dp, n);
        
        return Solve(n, dp);
    }
    
    private int Solve(int n, int[]dp){
        if (n == 0) return 0;
        
        if (dp[n] != -1)    return dp[n];
        
        int mini = int.MaxValue;
        for (int i = 1; i * i <= n; i++){
            mini = Math.Min(mini, 1 + Solve(n - (i * i), dp));
        }
        
        return dp[n] = mini;
    }
    
    private void InitDP(int[] dp, int n){
        for (int i = 0; i <= n; i++){
            dp[i] = -1;
        }
    }
}