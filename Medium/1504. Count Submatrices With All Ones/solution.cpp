class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int ans = 0;

        for (int i = 0; i < mat.size(); i++){
            for (int j = 0; j < mat[0].size(); j++){
                int rightBoundary = mat[0].size();
                for (int k = i; k < mat.size() && mat[k][j] == 1; k++){
                    for (int l = j; l < rightBoundary; l++){
                        if (mat[k][l] == 1){
                            ans++;
                        }
                        else{
                            rightBoundary = l;
                            break;
                        }
                    }
                }
            }
        }

        return ans;
    }
};