class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int up = 0;
        for (int left = 0, right = n - 1; left < right; left++, right--){
            cout << up << " " << left << " " << right << endl;
            for (int i = left; i < right; i++){
                
                int cur_row = up;
                int cur_col = i;
                int pre_val = matrix[up][i]; 
                    
                while (true){
                    int next_row = cur_col;
                    int next_col = (n - 1) - cur_row;
                    
                    cout << cur_row << " " << cur_col << " " << next_row << " " << next_col << " - " << pre_val << "<->" << matrix[next_row][next_col] << endl;
                    swap(pre_val, matrix[next_row][next_col]);
                    
                    if (next_row == up && next_col == i){
                        break;
                    }
                    
                    cur_row = next_row;
                    cur_col = next_col;
                }
                cout << endl;
                
            }
            up++;
        }
    }
};

/*
00 - 01 - 02 - 03
10 - 11 - 12 - 13
20 - 21 - 22 - 23
30 - 31 - 32 - 33

00 -> 03
01 -> 13
02 -> 23
03 -> 33

10 -> 02
11 -> 12
12 -> 22
13 -> 32

20 -> 01
21 -> 11
22 -> 21
23 -> 31

col = (n - 1) - row
row = col
  
*/
