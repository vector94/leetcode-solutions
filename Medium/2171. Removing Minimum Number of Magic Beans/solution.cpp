class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        
        if (beans.size() == 1)  return 0;
        
        sort(beans.begin(), beans.end());
        
        vector<long long> prefixSum(beans.size());
        
        for (int i = 0; i < beans.size(); i++){
            if (i == 0){
                prefixSum[i] = beans[i];
            }
            else{
                prefixSum[i] = prefixSum[i - 1] + beans[i];
            }
        }
        
        int n = beans.size();
        long long result = prefixSum.back();
        
        for (int i = 0; i < beans.size(); i++){
            if (i == 0){
                result = min(result, (prefixSum[n - 1] - prefixSum[i]) - (long long)(n - i - 1) * beans[i]);
            }
            else{
                result = min(result, prefixSum[i - 1] + (prefixSum[n - 1] - prefixSum[i]) - (long long)(n - i - 1) * beans[i]);
            }
        }
        
        return result;
        
    }
};