class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> sum(1005, 0);
        for (int i = 0; i < trips.size(); i++){
            sum[trips[i][1]] += trips[i][0];
            sum[trips[i][2]] -= trips[i][0];
        }
        
        for (int i = 0; i <= 1000; i++){
            if (i > 0)  sum[i] += sum[i - 1];
            if (sum[i] > capacity)  return false;
        }
        
        return true;
    }
};