class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            if (a[0] == b[0]){
                return a[1] > b[1];
            } 
            return a[0] < b[0];
        });
        
        int cnt = 0;
        int pre = 0;
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[pre][0] <= intervals[i][0] && intervals[i][1] <= intervals[pre][1]){
                cnt++;
            }
            else{
                pre = i;
            }
        }
        
        return intervals.size() - cnt;
    }
};