public class Solution {
    public int LongestCommonSubsequence(string text1, string text2) {
        var dp = new int[text1.Length, text2.Length];

        InitDP(text1, text2, dp);

        return Solve(0, 0, text1, text2, dp);
    }

    private int Solve(int i, int j, string text1, string text2, int[,] dp){
        if (i == text1.Length || j == text2.Length)
            return 0;

        if (dp[i, j] != -1)
            return dp[i, j];
        
        int result = 0;
        if (text1[i] == text2[j])
            result = 1 + Solve(i + 1, j + 1, text1, text2, dp);
        else
            result = Math.Max(Solve(i + 1, j, text1, text2, dp), Solve(i, j + 1, text1, text2, dp));

        dp[i, j] = result;
        return result;
    }

    private void InitDP(string text1, string text2, int[,] dp){
        for (int i = 0; i < text1.Length; i++){
            for (int j = 0; j < text2.Length; j++){
                dp[i, j] = -1;
            }
        }
    }
}