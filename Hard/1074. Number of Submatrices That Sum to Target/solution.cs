public class Solution {
    public int NumSubmatrixSumTarget(int[][] matrix, int target) {
        int noOfRows = matrix.Length;
        int noOfColumns = matrix[0].Length;

        int[,] prefixSum = new int[noOfRows + 1, noOfColumns + 1];
        InitPrefixSum(matrix, prefixSum, noOfRows, noOfColumns);

        int ans = 0;

        for (int up = 1; up <= noOfRows; up++){
            for (int down = up; down <= noOfRows; down++){
                for (int left = 1; left <= noOfColumns; left++){
                    for (int right = left; right <= noOfColumns; right++){
                        int curSum = prefixSum[down, right] - prefixSum[down, left - 1] - prefixSum[up - 1, right] + prefixSum[up - 1, left - 1];
                        if (curSum == target){
                            ans++;
                        }
                    }
                }
            }
        }

        return ans;
    }

    private void InitPrefixSum(int[][] matrix, int[,] prefixSum, int noOfRows, int noOfColumns){
        for (int i = 0; i <= noOfRows; i++){
            for (int j = 0; j <= noOfColumns; j++){
                if (i == 0 || j == 0){
                    prefixSum[i, j] = 0;
                }
                else{
                    Console.WriteLine(i + " " + j);
                    prefixSum[i, j] = matrix[i - 1][j - 1] + prefixSum[i - 1, j] + prefixSum[i, j - 1] - prefixSum[i - 1, j - 1];
                }
            }
        }
        Console.WriteLine("here");
    }
}