public class Solution {
    public int FurthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<int, int> myQueue = new PriorityQueue<int, int>();

        for (int i = 1; i < heights.Length; i++){
            int difference = heights[i] - heights[i - 1];

            if (difference > 0){
                bricks -= difference;
                myQueue.Enqueue(-difference, -difference);

                if (bricks < 0){
                    if (ladders == 0){
                        return i - 1;
                    }
                    else{
                        ladders--;
                        bricks -= myQueue.Dequeue();
                    }
                }
            }
        }

        return heights.Length - 1;
    }
}