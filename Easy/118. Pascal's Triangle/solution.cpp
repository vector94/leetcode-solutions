class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ret;
        vector<int> pre;
        for (int i = 1; i <= numRows; i++){
            vector<int> v;
            for (int j = 1; j <= i; j++){
                if (j == 1 || j == i){
                    v.push_back(1);
                }
                else{
                    v.push_back(pre[j - 2] + pre[j - 1]);
                }
            }
            ret.push_back(v);
            pre = v;
        }
        return ret;
    }
};