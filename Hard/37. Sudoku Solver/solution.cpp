class Solution {
public:

    void solveHelper(int r, int c, vector<vector<char>>& board, vector<vector<bool> > &row, vector<vector<bool> > &col, vector<vector<bool> > &square,
                    bool &found, vector<vector<char> > &result){
        if (found)  return;
        if (r == 9){
            result = board;
            found = true;
            return;
        }

        if (board[r][c] != '.'){
            if (c == 8) solveHelper(r + 1, 0, board, row, col, square, found, result);
            else        solveHelper(r, c + 1, board, row, col, square, found, result);
            return;
        }
        
        int squareNo = (r / 3) * 3 + (c / 3);
        for (int num = 1; num <= 9; num++){
            if (row[r][num] || col[c][num] || square[squareNo][num]){
                continue;
            }
            
            row[r][num] = true;
            col[c][num] = true;
            square[squareNo][num] = true;
            
            board[r][c] = num + '0';

            if (c == 8){
                solveHelper(r + 1, 0, board, row, col, square, found, result);
            }
            else{
                solveHelper(r, c + 1, board, row, col, square, found, result);
            }
            
            if (found)  return;
            
            row[r][num] = false;
            col[c][num] = false;
            square[squareNo][num] = false;
            
            board[r][c] = '.';
        }
    }
    

    
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool> > row(10, vector<bool> (10, false));
        vector<vector<bool> > col(10, vector<bool> (10, false));
        vector<vector<bool> > square(10, vector<bool> (10, false));

        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    row[i][num] = true;
                    col[j][num] = true;
                    int squareNo = (i / 3) * 3 + (j / 3);
                    square[squareNo][num] = true;
                }
            }
        }
        bool found = false;
        vector<vector<char> > result;
        solveHelper(0, 0, board, row, col, square, found, result);
        board = result;
    }
};

// [["5","3","1","2","7","3","4","6","7"],
//  ["6","2","3","1","9","5","1","5","8"],
//  ["9","9","8","1","4","5","2","6","3"],
//  ["8","1","2","3","6","4","5","7","3"],
//  ["4","3","5","8","1","3","6","2","1"],
//  ["7","6","9","5","2","2","3","1","6"],
//  ["1","6","4","6","2","7","2","8","5"],
//  ["2","5","6","4","1","9","7","3","5"],
//  ["3","7","8","4","8","1","9","7","9"]]
 




