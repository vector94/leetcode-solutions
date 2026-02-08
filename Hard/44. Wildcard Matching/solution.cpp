class Solution {
public:
    int solve(int i, int j, string &s, string &p, vector<vector<int> > &dp){
        int &ret = dp[i][j];
        if (ret != -1)  return ret;
        if (i == s.size() && j == p.size()) return ret = 1;
        if (j == p.size() || (i == s.size() && p[j] != '*')) return ret = 0;
        ret = 0;
        if (i < s.size() && p[j] != '?' && p[j] != '*' && s[i] != p[j])   return ret;
        if (i < s.size() && (p[j] != '?' || p[j] != '*') && s[i] == p[j])   return ret |= solve(i + 1, j + 1, s, p, dp);
        if (p[j] == '?')    return ret |= solve(i + 1, j + 1, s, p, dp);
        for (int k = 0; k <= (int)s.size() - i; k++){
            ret |= solve(i + k, j + 1, s, p, dp);
        }
        return ret;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int> > dp(n + 1, vector<int> (m + 1, -1));
        int result = solve(0, 0, s, p, dp);
        return result == 1 ? true: false;
    }
};