public class Solution {
    public int OrangesRotting(int[][] grid) {
        int m = grid.Length;
        int n = grid[0].Length;
        
        int result = 0;
        
        Queue<Tuple<int, int, int> > myQueue = new Queue <Tuple<int, int, int> >();
        
        for (int i = 0; i < grid.Length; i++){
            for (int j = 0; j < grid[i].Length; j++){
                if (grid[i][j] == 2){
                    myQueue.Enqueue(new Tuple<int, int, int> (i, j, 0));
                }
            }
        }
        
        int[] y = {-1, 1, 0, 0};
        int[] x = {0, 0, -1, 1};
        
        while (myQueue.Count > 0){
            Tuple<int, int, int> cur = myQueue.Peek();
            myQueue.Dequeue();
            
            for (int i = 0; i < 4; i++){
                int nextRow = cur.Item1 + y[i];
                int nextCol = cur.Item2 + x[i];
                
                if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && grid[nextRow][nextCol] == 1){
                    grid[nextRow][nextCol] = 2;
                    result = Math.Max(result, cur.Item3 + 1);
                    myQueue.Enqueue(new Tuple<int, int, int> (nextRow, nextCol, cur.Item3 + 1));
                }
            }
        }
        
        for (int i = 0; i < grid.Length; i++){
            for (int j = 0; j < grid[i].Length; j++){
                if (grid[i][j] == 1)    return -1;
            }
        }
        
        return result;
    }
}