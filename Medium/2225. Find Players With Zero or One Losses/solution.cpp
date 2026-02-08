class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> win, lose;
        for (int i = 0; i < matches.size(); i++){
            win[matches[i][0]]++;
            lose[matches[i][1]]++;
        }
        vector<vector<int> > result;
        set<int> a0, a1;
        for (int i = 0; i < matches.size(); i++){
            if (lose[matches[i][0]] == 0){
                a0.insert(matches[i][0]);
            }
            if (lose[matches[i][1]] == 1){
                a1.insert(matches[i][1]);
            }
        }
        result.push_back(vector<int>(a0.begin(), a0.end()));
        result.push_back(vector<int>(a1.begin(), a1.end()));
        return result;
    }
};