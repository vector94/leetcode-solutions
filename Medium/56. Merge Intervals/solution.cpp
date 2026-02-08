class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > result;
        
        int preLeft = intervals[0][0];
        int preRight = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++){
            if (preLeft <= intervals[i][0] && intervals[i][0] <= preRight){
                preRight = max(preRight, intervals[i][1]);
            }
            else{
                result.push_back(vector<int> {preLeft, preRight});
                preLeft = intervals[i][0];
                preRight = intervals[i][1];
            }
        }
        result.push_back(vector<int> {preLeft, preRight});
        return result;
    }
};