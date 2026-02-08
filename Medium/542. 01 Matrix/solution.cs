public class Solution {
    public int[][] UpdateMatrix(int[][] mat) {
        
        int m = mat.Length;
        if (m == 0) return mat;
        
        int n = mat[0].Length;
        int[][] result = new int[m][];
        for (int i = 0; i < m; i++){
            result[i] = new int[n];
        }
        
        Queue<Tuple<int,int> > myQueue = new Queue<Tuple<int,int> >();
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 0){
                    mat[i][j] = -1;
                    myQueue.Enqueue(new Tuple<int, int>(i, j));
                    result[i][j] = 0;
                }
            }
        }
        
        int[] y = {-1, 1, 0, 0};
        int[] x = {0, 0, -1, 1};
        
        while (myQueue.Count > 0){
            Tuple<int, int> currentPair = myQueue.Peek();
            myQueue.Dequeue();
            
            for (int i = 0; i < 4; i++){
                int nextRow = currentPair.Item1 + y[i];
                int nextCol = currentPair.Item2 + x[i];
                
                if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && mat[nextRow][nextCol] != -1){
                    result[nextRow][nextCol] = 1 + result[currentPair.Item1][currentPair.Item2];
                    myQueue.Enqueue(new Tuple<int, int> (nextRow, nextCol));
                    mat[nextRow][nextCol] = -1;
                }
            }
        }
        
        return result;
    
    }
}