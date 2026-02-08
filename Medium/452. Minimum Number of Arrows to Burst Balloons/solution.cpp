class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end(), [](vector<int> &p1, vector<int> &p2){
            return p1[1] < p2[1]; 
        });
        
        int result = 1;
        
        int pre = points[0][1];
        
        for (int i = 0; i < points.size(); i++){
            if (points[i][0] > pre){
                pre = points[i][1];
                result++;
            }
        }
        
        return result;
    }
};