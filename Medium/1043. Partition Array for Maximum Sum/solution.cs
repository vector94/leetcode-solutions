public class Solution {
    public int MaxSumAfterPartitioning(int[] arr, int k) {
        int[] dp = new int[arr.Length];

        return Solve(0, k, arr, dp);
    }

    private int Solve(int index, int k, int[] arr, int[] dp){
        if (index >= arr.Length)    return 0;
        if (dp[index] != 0)    return dp[index];

        int maxElem = 0;
        int maxResult = 0;
        for (int i = index; i < Math.Min(arr.Length, index + k); i++){
            maxElem = Math.Max(maxElem, arr[i]);
            maxResult = Math.Max(maxResult, maxElem * (i - index + 1) + Solve(i + 1, k, arr, dp));
        }
        return dp[index] = maxResult;
    }
}