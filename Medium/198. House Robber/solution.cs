public class Solution {
    public int Rob(int[] nums) {
        var dp = new int[105, 105];

        InitDP(ref dp, nums.Length);

        return Solve(-1, 0, nums, dp);
    }

    private int Solve(int prevIndex, int curIndex, int[] nums, int[,] dp){
        if (curIndex == nums.Length){
            return 0;
        }

        if (dp[prevIndex + 1, curIndex] != -1){
            return dp[prevIndex + 1, curIndex];
        }

        int result = Solve(prevIndex, curIndex + 1, nums, dp);
        if (prevIndex == -1 || (curIndex - 1) > prevIndex){
            result = Math.Max(result, nums[curIndex] + Solve(curIndex, curIndex + 1, nums, dp));
        }

        Console.WriteLine(prevIndex + " " + curIndex + " " + result);

        dp[prevIndex + 1, curIndex] = result;
        return result;
    }

    private void InitDP(ref int[,] dp, int length){
        for (int i = 0; i <= length; i++){
            for (int j = 0; j <= length; j++){
                dp[i, j] = -1;
            }
        }
    }
}