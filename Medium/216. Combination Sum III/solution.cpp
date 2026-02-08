class Solution {
public:
    
    void backtrack(int curNum, int k, int n, vector<int> &v, vector<vector<int>> &result){
        if (n == 0 && k == 0){
            result.push_back(v);
            return;
        }
        else if (n == 0 || k == 0 || curNum > 9)    return;
        for (int i = curNum; i <= 9; i++){
            if (n >= i){
                v.push_back(i);
                backtrack(i + 1, k - 1, n - i, v, result);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > result;
        vector<int> v;
        backtrack(1, k, n, v, result);
        return result;
    }
};