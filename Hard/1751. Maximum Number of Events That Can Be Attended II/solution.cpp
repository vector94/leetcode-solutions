class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int N = events.size();
        sort(events.begin(), events.end());

        // for (vector<int> event : events){
        //     cout << event[0] << " " << event[1] << " " << event[2] << endl;
        // }
        // cout << "------------" << endl;

        vector<vector<int>> dp(N, vector<int>(k + 1, -1));

        return solve(0, k, events, dp);
    }

    int solve(int idx, int k, vector<vector<int>>& events, vector<vector<int>>& dp){
        if (k == 0 || idx == events.size()) return 0;

        if (dp[idx][k] != -1)   return dp[idx][k];

        int ans = solve(idx + 1, k, events, dp);

        int nextIdx = idx + 1;
        while (nextIdx < events.size() && events[nextIdx][0] <= events[idx][1]){
            nextIdx++;
        } 

        ans = max(ans, events[idx][2] + solve(nextIdx, k - 1, events, dp));

        return dp[idx][k] = ans;
    }
};