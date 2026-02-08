class Solution {
public:
    
    void dfs(int x, int y, vector<vector<char> >&board, vector<vector<int> > &dir){
        board[x][y] = 'o';
        
        for (int i = 0; i < 4; i++){
            int nextX = x + dir[i][0];
            int nextY = y + dir[i][1];
            
            if (nextX >= 0 && nextX < board.size() && nextY >= 0 && nextY < board[0].size() && board[nextX][nextY] == 'O'){
                dfs(nextX, nextY, board, dir);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        vector<vector<int> > dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for (int i = 0; i < board.size(); i++){
            if (board[i][0] == 'O'){
                dfs(i, 0, board, dir);
            }
            if (board[i][board[i].size() - 1] == 'O'){
                dfs(i, board[i].size() - 1, board, dir);
            }
        }
        
        for (int i = 0; i < board[0].size(); i++){
            if (board[0][i] == 'O'){
                dfs(0, i, board, dir);
            }
            if (board[board.size() - 1][i] == 'O'){
                dfs(board.size() - 1, i, board, dir);
            }
        }
        
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'o') board[i][j] = 'O';
            }
        }
    }
};