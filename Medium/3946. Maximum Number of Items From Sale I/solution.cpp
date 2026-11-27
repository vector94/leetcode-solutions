class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if (a[1] == b[1]){
            return a[2] > b[2];
        }
        return a[1] < b[1];
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int N = items.size();

        for (int i = 0; i < N; i++){
            int factorCnt = 0;
            for (int j = 0; j < N; j++){
                if (i == j) continue;

                if (items[j][0] % items[i][0] == 0){
                    factorCnt++;
                }   
            }

            items[i].push_back(factorCnt);
        }

        sort(items.begin(), items.end(), cmp);
        
        vector<vector<int>> dp(N, vector<int>(budget + 1, -1));

        return solve(0, budget, items, dp);
    }

    int solve(int idx, int budget, vector<vector<int>>& items, vector<vector<int>>& dp){
        if (idx == items.size() || budget < items[idx][1]){
            return budget / items[0][1];
        }

        if (dp[idx][budget] != -1)  return dp[idx][budget];

        int ret = solve(idx + 1, budget, items, dp);
        ret = max(ret, 1 + items[idx][2] + solve(idx + 1, budget - items[idx][1], items, dp));

        return dp[idx][budget] = ret;
    }
};