class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> xCordinates;
        vector<pair<int, int>> yCordinates;

        for (int i = 0; i < rectangles.size(); i++){
            xCordinates.push_back({rectangles[i][0], rectangles[i][2]});
            yCordinates.push_back({rectangles[i][1], rectangles[i][3]});
        }

        sort(xCordinates.begin(), xCordinates.end());
        sort(yCordinates.begin(), yCordinates.end());

        // for (int i = 0; i < yCordinates.size(); i++){
        //     cout << xCordinates[i].first << " " << xCordinates[i].second << endl;
        // }
        // cout << "-------------------\n";
        // for (int i = 0; i < yCordinates.size(); i++){
        //     cout << yCordinates[i].first << " " << yCordinates[i].second << endl;
        // }

        int cnt = 0;
        int prev = xCordinates[0].second;
        for (int i = 1; i < xCordinates.size(); i++){
            if (xCordinates[i].first >= prev){
                cnt++;
            }
            prev = max(prev, xCordinates[i].second);
        }
        
        if (cnt >= 2)   return true;
        
        cnt = 0;
        prev = yCordinates[0].second;
        for (int i = 1; i < yCordinates.size(); i++){
            if (yCordinates[i].first >= prev){
                cnt++;
            }
            prev = max(prev, yCordinates[i].second);
        }
        
        if (cnt >= 2)   return true;
        return false;
    }
};