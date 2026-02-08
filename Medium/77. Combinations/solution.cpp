class Solution {
public:
    void cal(int i, int n, int k, vector<int> &v, vector<vector<int>> &result){
        if (i > n){
            if (v.size() == k){
                result.push_back(v);
            }
            return;
        }
        cal (i + 1, n, k, v, result);
        if (v.size() < k){
            v.push_back(i);
            cal(i + 1, n, k, v, result);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> v;
        cal(1, n, k, v, result);
        return result;
    }
};