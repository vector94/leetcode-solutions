class Solution {
public:
    
    void visitMark(vector<vector<int> > &heights, vector<vector<bool> > &ocean, queue<pair<int, int> > &myQueue){
        while (!myQueue.empty()){
            int curRow = myQueue.front().first;
            int curCol = myQueue.front().second;
            
            myQueue.pop();
            
            vector<int> dir_x {1, -1, 0, 0};
            vector<int> dir_y {0, 0, 1, -1};
            
            for (int i = 0; i < 4; i++){
                int nextRow = curRow + dir_x[i];
                int nextCol = curCol + dir_y[i];
                
                if (nextRow >= 0 && nextRow < heights.size() && nextCol >= 0 && nextCol < heights[0].size() && !ocean[nextRow][nextCol] && heights[nextRow][nextCol] >= heights[curRow][curCol]){
                    ocean[nextRow][nextCol] = true;
                    myQueue.push({nextRow, nextCol});
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<bool> > pacific(n, vector<bool> (m, false));
        vector<vector<bool> > atlantic(n, vector<bool> (m, false));
        
        queue<pair<int, int> > myQueue1;
        for (int i = 0; i < n; i++){
            myQueue1.push({i, 0});
            pacific[i][0] = true;
        }
        for (int i = 0; i < m; i++){
            myQueue1.push({0, i});
            pacific[0][i] = true;
        }
        
        visitMark(heights, pacific, myQueue1);
        
        queue<pair<int, int> > myQueue2;
        for (int i = 0; i < n; i++){
            myQueue2.push({i, m - 1});
            atlantic[i][m - 1] = true;
        }
        for (int i = 0; i < m; i++){
            myQueue2.push({n - 1, i});
            atlantic[n - 1][i] = true;
        }
        
        visitMark(heights, atlantic, myQueue2);
        
        vector<vector<int> > result;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (pacific[i][j] && atlantic[i][j]){
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};