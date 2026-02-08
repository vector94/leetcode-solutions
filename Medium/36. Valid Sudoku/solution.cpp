class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, bool> hashMap;

        for (int i = 0; i < 9; i++){
            hashMap.clear();
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                if (hashMap[board[i][j]]){
                    return false;
                }

                hashMap[board[i][j]] = true;
            }
        }

        for (int j = 0; j < 9; j++){
            hashMap.clear();
            for (int i = 0; i < 9; i++){
                if (board[i][j] == '.') continue;
                if (hashMap[board[i][j]]){
                    return false;
                }

                hashMap[board[i][j]] = true;
            }
        }

        for (int i = 0; i < 9; i += 3){
            for (int j = 0; j < 9; j += 3){
                hashMap.clear();

                for (int p = i; p < i + 3; p++){
                    for (int q = j; q < j + 3; q++){
                        if (board[p][q] == '.') continue;
                        if (hashMap[board[p][q]]){
                            return false;
                        }
                        hashMap[board[p][q]]= true;
                    }
                }
            }
        }

        return true;
    }
};