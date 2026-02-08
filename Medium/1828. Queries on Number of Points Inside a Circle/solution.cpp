class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> result;
        
        for (int i = 0; i < queries.size(); i++){
            int cnt = 0;
            for (int j = 0; j < points.size(); j++){
                if ((queries[i][0] - points[j][0]) * (queries[i][0] - points[j][0]) + 
                    (queries[i][1] - points[j][1]) * (queries[i][1] - points[j][1]) <= queries[i][2] * queries[i][2]){
                    cnt++;
                }
            }
            result.push_back(cnt);
        }
        
        return result;
    }
};