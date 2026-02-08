class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &p1, vector<int> &p2){
            return p1[1] < p2[1];
        });
        int result = 1;
        int curRight = points[0][1];
        for (int i = 1; i < points.size(); i++){
            if (points[i][0] > curRight){
                result++;
                curRight = points[i][1];
            }
        }
        return result;
    }
};