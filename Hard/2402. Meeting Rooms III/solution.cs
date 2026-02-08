public class Solution {
    
  public int MostBooked(int n, int[][] meetings) {
        int[] rooms = new int[n];
        
        PriorityQueue<List<long>, long> occupiedRooms = new PriorityQueue<List<long>, long>(Comparer<long>.Create((x, y) => x.CompareTo(y)));
        
        PriorityQueue<long, long> freeRooms = new PriorityQueue<long, long>();
        for (int i = 0; i < n; i++) {
            freeRooms.Enqueue(i, i);
        }

        Array.Sort(meetings, (x, y) => x[0].CompareTo(y[0]));
        long currentTime = 0;
        for (int i = 0; i < meetings.Length; i++) {
            int[] meeting = meetings[i];

            currentTime = Math.Max(meeting[0], currentTime);
            
            if (freeRooms.Count == 0) {
                long earliestFreeTime = occupiedRooms.Peek()[1];
                currentTime = Math.Max(earliestFreeTime, currentTime);
            }            
            
            while (occupiedRooms.Count > 0 && occupiedRooms.Peek()[1] <= currentTime) {
                long freedRoom = occupiedRooms.Dequeue()[2];
                freeRooms.Enqueue(freedRoom, freedRoom);
            }
            
            long nextRoom = freeRooms.Dequeue();
            rooms[nextRoom] += 1;
            occupiedRooms.Enqueue(new List<long>{ currentTime, currentTime + (meeting[1] - meeting[0]), nextRoom }, currentTime + (meeting[1] - meeting[0]));
        }
        
        int max = 0, ansRoom = 0;
        for (int i = n-1; i >= 0; i--) {
            if (rooms[i] >= max) {
                max = rooms[i];
                ansRoom = i;
            }
        }
        return ansRoom;   
    }
}