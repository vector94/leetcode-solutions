class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        vector<int> dist(N * N + 1, -1);
        dist[1] = 0;
        queue<pair<int, int>> myQueue;
        myQueue.push({1, 1});

        while (!myQueue.empty()){
            int y = myQueue.front().first;
            int x = myQueue.front().second;

            myQueue.pop();
            
            int curCellValue = getCellValue(N, y, x);
            
            for (int i = 1; i <= 6; i++){
                int nextCellValue = curCellValue + i;
                if (nextCellValue > N * N)  break;

                pair<int, int> nextCoordinate = getCoordinate(N, nextCellValue);
                int ny = nextCoordinate.first;
                int nx = nextCoordinate.second;

                if (board[N - ny][nx - 1] != -1){
                    nextCellValue = board[N - ny][nx - 1];
                }

                if (dist[nextCellValue] != -1)  continue;

                dist[nextCellValue] = 1 + dist[curCellValue];

                nextCoordinate = getCoordinate(N, nextCellValue);
                ny = nextCoordinate.first;
                nx = nextCoordinate.second;
                
                myQueue.push({ny, nx});
            }
        }

        return dist[N * N];
    }

    int getCellValue(int N, int y, int x){
        int curCellValue = (y - 1) * N;
        if (y & 1){
            curCellValue += x;
        }
        else{
            curCellValue += (N - x) + 1;
        }

        return curCellValue;
    }

    pair<int, int> getCoordinate(int N, int cellValue){
        int y = (cellValue + (N - 1)) / N;
        int x;
        if (y & 1){
            int rem = cellValue % N;
            if (rem == 0){
                x = N;
            }
            else{
                x = rem;
            }
        }
        else{
            int rem = cellValue % N;
            if (rem == 0){
                x = 1;
            }
            else{
                x = N - rem + 1;
            }
        }

        return {y, x};
    }

};