class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if (newColor == image[sr][sc])  return image;
        
        int m = image.size();
        int n = image[0].size();
        int curColor = image[sr][sc];
        
        queue<pair<int, int> > Q;
        image[sr][sc] = newColor;
        Q.push({sr, sc});
        
        int y[] = {-1, 1, 0, 0};
        int x[] = {0, 0, -1, 1};
        
        while (!Q.empty()){
            int curY = Q.front().first;
            int curX = Q.front().second;
            
            Q.pop();
            
            for (int i = 0; i < 4; i++){
                int nextY = curY + y[i];
                int nextX = curX + x[i];
                
                if (nextY >= 0 && nextY < m && nextX >= 0 && nextX < n && image[nextY][nextX] == curColor){
                    image[nextY][nextX] = newColor;
                    Q.push({nextY, nextX});
                }
            }
        }
        
        return image;
    }
};
