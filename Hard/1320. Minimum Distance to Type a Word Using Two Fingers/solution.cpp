class Solution {
public:

    int dp[30][30][305];

    int getDistance(char prev, char cur, unordered_map<char, pair<int, int>>& coordinate){
        return abs(coordinate[prev].first - coordinate[cur].first) + 
            abs(coordinate[prev].second - coordinate[cur].second);
    }

    int minimumDistance(string word) {
        unordered_map<char, pair<int, int>> coordinate;

        char curChar = 'A';
        int i = 0;
        int j = 0;

        while (curChar <= 'Z'){
            coordinate[curChar] = {i, j};
            curChar++;
            j++;
            if (j % 6 == 0){
                j = 0;
                i++;
            }
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, word, coordinate);
    }

    int solve(int prev1, int prev2, int idx, string &word, unordered_map<char, pair<int, int>> &coordinate){
        if (idx == word.size()) return 0;

        if (dp[prev1][prev2][idx] != -1)    return dp[prev1][prev2][idx];

        int dist1, dist2;

        if (prev1 == 0){
            dist1 = solve(word[idx] - 'A' + 1, prev2, idx + 1, word, coordinate);
        }
        else{
            dist1 = getDistance((char)prev1 + 'A' - 1, word[idx], coordinate) + 
                solve(word[idx] - 'A' + 1, prev2, idx + 1, word, coordinate);
        }

        if (prev2 == 0){
            dist2 = solve(prev1, word[idx] - 'A' + 1, idx + 1, word, coordinate);
        }
        else{
            dist2 = getDistance((char)prev2 + 'A' - 1, word[idx], coordinate) + 
                solve(prev1, word[idx] - 'A' + 1, idx + 1, word, coordinate);
        }


        return dp[prev1][prev2][idx] = min(dist1, dist2);
    }
};