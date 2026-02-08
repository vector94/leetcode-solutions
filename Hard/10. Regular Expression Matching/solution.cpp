class Solution {
public:
    
    int solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        cout << i << " " << j << endl;
        if (i == -1 && j == -1){
            return 1;
        }
        if (j == -1){
            return 0;
        }
        else if (i == -1){
            int flag = 1;
            for (int k = j; k >= 0; k--){
                if (p[k] != '*'){
                    flag = 0;
                    break;
                }
                k--;
            }
            return flag;
        }
        int ret = dp[i][j];
        if (ret != -1){
            return ret;
        }
        ret = 0;
        if ((isalpha(p[j])) && s[i] != p[j]){
            cout << "here1" << endl;
            ret = 0;
        }
        else if (p[j] == '.'){
            cout << "here2" << endl;
            ret = solve(i - 1, j - 1, s, p, dp);   
        }
        else if (p[j] == '*'){
            cout << "here3" << endl;
            ret = solve(i, j - 2, s, p, dp);
            for (int k = i; k >= 0 && ((s[k] == p[j - 1]) || p[j - 1] == '.'); k--){
                ret |= solve(k - 1, j - 2, s, p, dp);
            }
        }
        else{
            cout << "here4" << endl;
            ret = solve(i - 1, j - 1, s, p, dp);
        }
        return dp[i][j] = ret;
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int> (p.size(), -1));
        return solve(s.size() - 1, p.size() - 1, s, p, dp);
    }
};