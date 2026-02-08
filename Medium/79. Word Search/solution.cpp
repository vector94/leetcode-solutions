class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool> > mark(m, vector<bool> (n, false));
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == word[0]){
                    mark[i][j] = true;
                    bool isFound = dfs(i, j, 1, board, word, mark);
                    mark[i][j] = false;
                    if (isFound)    return true;
                }
            }
        }

        return false;
    }
    
    
private:
    bool dfs(int i, int j, int k, vector<vector<char>> &board, string word, vector<vector<bool> > &mark){
        if (k == word.size())   return true;
        
        int dy[] = {-1, 0, 1, 0};
        int dx[] = {0, -1, 0, 1};
        
        bool isFound = false;
        
        for (int l = 0; l < 4; l++){
            int ny = i + dy[l];
            int nx = j + dx[l];
            
            if (ny >= 0 && ny < board.size() && nx >= 0 && nx < board[0].size() && board[ny][nx] == word[k] && !mark[ny][nx]){
                mark[ny][nx] = true;
                isFound |= dfs(ny, nx, k + 1, board, word, mark);
                mark[ny][nx] = false;
            }
        }
        return isFound;
    }
};