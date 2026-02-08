class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rows;
        
        for (int i = 0; i < mat.size(); i++){
            int soldier = 0;
            for (int j = 0; j < mat[i].size(); j++){
                if (mat[i][j] == 0) break;
                soldier++;
            }
            rows.push_back({i, soldier});
        }
        
        sort(rows.begin(), rows.end(), [](pair<int, int> p1, pair<int, int> p2){
            if (p1.second == p2.second){
                return p1.first < p2.first;
            }
            return p1.second < p2.second;
        });
        
        vector<int> result;
        
        for (int i = 0; i < k; i++){
            result.push_back(rows[i].first);
        }
        
        return result;
    }
};