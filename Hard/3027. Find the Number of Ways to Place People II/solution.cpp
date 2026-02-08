class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b){
        if (a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);

        int ans = 0;
        for (int i = 0; i < points.size(); i++){
            
            int maxValidY = -2e9;
            for (int j = i + 1; j < points.size(); j++){
                if (points[i][0] <= points[j][0] && points[i][1] >= points[j][1] && points[j][1] > maxValidY){
                    ans++;
                    maxValidY = max(maxValidY, points[j][1]);
                }
            }
        }

        return ans;
    }
};