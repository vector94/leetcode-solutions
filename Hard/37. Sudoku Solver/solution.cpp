class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowMap(10, vector<bool> (10, false));
        vector<vector<bool>> colMap(10, vector<bool> (10, false));
        vector<vector<bool>> sqMap(10, vector<bool> (10, false));

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    int num = board[i][j] - '0';

                    int sqNum = (i / 3) * 3 + j / 3;

                    rowMap[i][num] = true;
                    colMap[j][num] = true;
                    sqMap[sqNum][num] = true;
                }
            }
        }

        bool found = false;
        solveSudokuHelper(0, 0, board, rowMap, colMap, sqMap, found);
    }

    void solveSudokuHelper(int r, int c, 
        vector<vector<char>>& board,
        vector<vector<bool>>& rowMap,
        vector<vector<bool>>& colMap,
        vector<vector<bool>>& sqMap,
        bool &found
    ){
        if (found)  return;
        if (r == 9){
            found = true;
            return;
        }

        if (board[r][c] != '.'){
            if (c == 8){
                solveSudokuHelper(r + 1, 0, board, rowMap, colMap, sqMap, found);
            }
            else{
                solveSudokuHelper(r, c + 1, board, rowMap, colMap, sqMap, found);
            }
            return;
        }

        for (char ch = '1'; ch <= '9'; ch++){
            int num = ch - '0';
            int sqNum = (r / 3) * 3 + (c / 3);
            if (rowMap[r][num] || colMap[c][num] || sqMap[sqNum][num]){
                continue;
            }

            rowMap[r][num] = true;
            colMap[c][num] = true;
            sqMap[sqNum][num] = true;
            board[r][c] = ch;

            if (c == 8){
                solveSudokuHelper(r + 1, 0, board, rowMap, colMap, sqMap, found);
            }
            else{
                solveSudokuHelper(r, c + 1, board, rowMap, colMap, sqMap, found);
            }

            if (found)  return;
            
            rowMap[r][num] = false;
            colMap[c][num] = false;
            sqMap[sqNum][num] = false;
            board[r][c] = '.';
        }
    }
};