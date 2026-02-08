class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                for (int k = 1; i + k <= matrix.size() && j + k <= matrix[0].size(); k++){
                    if (check(i, j, k, matrix)){
                        ans++;
                    }
                    else{
                        break;
                    }
                }
            }
        }

        return ans;
    }

    bool check(int i, int j, int k, vector<vector<int>>& matrix){
        for (int p = i; p < i + k; p++){
            for (int q = j; q < j + k; q++){
                if (matrix[p][q] == 0){
                    return false;
                }
            }
        }

        return true;
    }
};