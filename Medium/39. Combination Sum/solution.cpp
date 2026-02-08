class Solution {
public:
    
    void combinationSumHelper(int index, int need, vector<int> &candidates, vector<int> &v, vector<vector<int> > &result){
        if (need == 0){
            result.push_back(v);
            return;
        }
        if (index == candidates.size() || candidates[index] > need){
            return;
        }
        
        v.push_back(candidates[index]);
        combinationSumHelper(index, need - candidates[index], candidates, v, result);
        v.pop_back();
        
        combinationSumHelper(index + 1, need, candidates, v, result);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int> > result;
        
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(0, target, candidates, v, result);
        
        return result;
    }
};