class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int size = startTime.size();
        vector<vector<int>> job;
        vector<int> dp(size, -1);

        for (int i = 0; i < size; i++){
            job.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(job.begin(), job.end());
        sort(startTime.begin(), startTime.end());

        return f(0, job, startTime, dp);
    }

    int f(int idx, vector<vector<int>> &job, vector<int> &startTime, vector<int> &dp){
        if (idx == startTime.size()){
            return 0;
        }
        int &curProfit = dp[idx];
        if (curProfit != -1){
            return curProfit;
        }
        int nextIdx = lower_bound(startTime.begin(), startTime.end(), job[idx][1]) - startTime.begin();
        curProfit = job[idx][2] + f(nextIdx, job, startTime, dp);
        curProfit = max(curProfit, f(idx + 1, job, startTime, dp)); 
        return curProfit;
    }
};