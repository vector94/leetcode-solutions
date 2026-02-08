class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int ans = meetings[0][0] - 1;
        int prevDay = meetings[0][1];
        for (int i = 0; i < meetings.size(); i++){
            if (prevDay + 1 < meetings[i][0]){
                ans += (meetings[i][0] - prevDay) - 1;
            }
            prevDay = max(prevDay, meetings[i][1]);
        }

        if (prevDay < days){
            ans += days - prevDay;
        }

        return ans;
    }
};