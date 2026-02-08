class Solution {
private:
    int solve(int left, int right, string &s, vector<vector<int> > &dp){
        if (left == right)  return dp[left][right] = 1;
        if (left > right)   return 0;
        int &ret = dp[left][right];
        if (ret != -1)  return ret;
        if (s[left] == s[right]){
            ret = 2 + solve(left + 1, right - 1, s, dp);
        }
        else{
            ret = max(solve(left + 1, right, s, dp), solve(left, right - 1, s, dp));
        }
        return ret;
    } 
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));
        int result = solve(0, s.size() - 1, s, dp);
        return result;
    }
};