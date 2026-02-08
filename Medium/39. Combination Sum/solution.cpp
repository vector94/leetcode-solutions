class Solution {
public:
    
    void backtrack(int idx, int target, vector<int> &candidates, vector<int> &v, vector<vector<int> > &result){
        if (target == 0){
            result.push_back(v);
            return;
        }
        else if (idx == candidates.size()){
            return;
        }
        backtrack(idx + 1, target, candidates, v, result);
        if (target >= candidates[idx]){
            v.push_back(candidates[idx]);
            backtrack(idx, target - candidates[idx], candidates, v, result);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> v;
        
        backtrack(0, target, candidates, v, result);
            
        return result;
    }
};