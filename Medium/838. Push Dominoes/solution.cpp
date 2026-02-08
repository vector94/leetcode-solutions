class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<pair<int, int> > dir;
        dir.push_back({0, 0});
        for (int i = 0; i < dominoes.size(); i++){
            if (dominoes[i] == 'L'){
                dir.push_back({i + 1, 0});
            }
            else if (dominoes[i] == 'R'){
                dir.push_back({i + 1, 1});
            }
        }
        dir.push_back({dominoes.size() + 1, 1});
        
        string result = "";
        for (int i = 0; i < dir.size() - 1; i++){
            int length = dir[i + 1].first - dir[i].first + 1;
            if (dir[i].second == 0 && dir[i + 1].second == 0 || dir[i].second == 1 && dir[i + 1].second == 1){
                for (int cnt = 1; cnt < length; cnt++){
                    result += (dir[i].second == 0 ? "L" : "R");
                }
            }
            else if (dir[i].second == 1 && dir[i + 1].second == 0){
                for (int cnt = 1; cnt <= length / 2; cnt++){
                    result += "R";
                }
                if (length & 1) result += ".";
                for (int cnt = 1; cnt < length / 2; cnt++){
                    result += "L";
                }
            }
            else{
                result += "L";
                for (int cnt = 1; cnt < length - 1; cnt++){
                    result += ".";
                }
            }
        }
        
        result = result.substr(1, dominoes.size());
        return result;
    }
};


/*
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
L . L . R . . . L R . . L . . R
*/