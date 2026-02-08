class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<vector<int> > ret;
        vector<int> res;
        for (int i = 1; i <= numRows + 1; i++){
            vector<int> v;
            for (int j = 1; j <= i; j++){
                if (j == 1 || j == i){
                    v.push_back(1);
                }
                else{
                    v.push_back(ret[i - 2][j - 2] + ret[i - 2][j - 1]);
                }
            }
            ret.push_back(v);
            res = v;
        }
        return res;
    }
};