class Solution {
public:
    
    void combinationSum3Helper(int cur, int left, int sum, vector<vector<int> > &result, vector<int> &v){
        if (left == 0){
            if (sum == 0){
                result.push_back(v);
            }
            return;
        }
        if (sum == 0)   return;
        for (int num = cur; num <= 9; num++){
            if (sum >= num){
                v.push_back(num);
                combinationSum3Helper(num + 1, left - 1, sum - num, result, v);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > result;
        vector<int> v;
        
        combinationSum3Helper(1, k, n, result, v);
        return result;
    }
};