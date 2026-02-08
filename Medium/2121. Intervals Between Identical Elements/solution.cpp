class Solution {
public:
    long long totalCnt[100005], curCnt[100005];
    long long totalSum[100005], curSum[100005];
    
    
    vector<long long> getDistances(vector<int>& arr) {
        
        memset(totalCnt, 0, sizeof(totalCnt));
        memset(curCnt, 0, sizeof(curCnt));
        memset(totalSum, 0, sizeof(totalSum));
        memset(curSum, 0, sizeof(curSum));
        
        for (int i = 0; i < arr.size(); i++){
            totalCnt[arr[i]]++;
            totalSum[arr[i]] += i;
        }
        
        vector<long long> result;
        
        for (int i = 0; i < arr.size(); i++){
            if (totalCnt[arr[i]] == 0){
                result.push_back(0);
                continue;
            }
            
            long long curResult = (curCnt[arr[i]] * i) - curSum[arr[i]];
            curSum[arr[i]] += i;
            curCnt[arr[i]]++;
            curResult += (totalSum[arr[i]] - curSum[arr[i]]) - (totalCnt[arr[i]] - curCnt[arr[i]]) * i;
            
            result.push_back(curResult);
        }
        
        return result;
    }
};