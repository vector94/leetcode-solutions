class Solution {
public:
    
    void backtrack(int idx, int target, vector<int> &candidates, vector<int> &v, vector<vector<int> > &result){
        if (target == 0){
            result.push_back(v);
            return;
        }
        else if (idx == candidates.size())  return;
        for (int i = idx; i < candidates.size(); i++){
            if ((i == idx || candidates[i] != candidates[i - 1]) && target >= candidates[i]){
                v.push_back(candidates[i]);
                backtrack(i + 1, target - candidates[i], candidates, v, result);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, v, result);
        return result;
    }
};