class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& grid) {
        bool ret = true;
        for (int i = 0; i < 9; i++){
            set<int> st;
            for (int j = 0; j < 9; j++){
                if (grid[i][j] != '.'){
                    int x = grid[i][j] -'0';
                    if (st.find(x) != st.end()){
                        ret = false;
                        break;
                    }
                    else{
                        st.insert(x);
                    }
                }
            }
        }
        for (int j = 0; j < 9; j++){
            set<int> st;
            for (int i = 0; i < 9; i++){
                if (grid[i][j] != '.'){
                    int x = grid[i][j] -'0';
                    if (st.find(x) != st.end()){
                        ret = false;
                        break;
                    }
                    else{
                        st.insert(x);
                    }
                }
            }
        }
        for (int i = 0; i < 9; i += 3){
            for (int j = 0; j < 9; j += 3){
                set<int> st;
                for (int k = i, cnt1 = 0; cnt1 < 3; k++, cnt1++){
                    for (int l = j, cnt2 = 0; cnt2 < 3; l++, cnt2++){
                        if (grid[k][l] != '.'){
                            int x = grid[k][l] - '0';
                            if (st.find(x) != st.end()){
                                //cout << st.size() << " " << grid[k][l] << " " << x << endl;
                                ret = false;
                                break;
                            }
                            else{
                                st.insert(x);
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
};