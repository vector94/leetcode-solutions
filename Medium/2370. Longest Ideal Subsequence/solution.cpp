class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int> > dp(30, vector<int> (n, -1));
        
        int ans = 0;
        
        for (int i = 0; i < n; i++){
            ans = max(ans, longestIdealStringHelper(s[i] - 'a', i + 1, s, k, dp));
        }
        
        return ans + 1;
    }
    
private:
    int longestIdealStringHelper(int preChar, int i, string &s, int k, vector<vector<int> > &dp){
        if (i == s.size())  return 0;
        
        if (dp[preChar][i] != -1)    return dp[preChar][i];
        
        int result = longestIdealStringHelper(preChar, i + 1, s, k, dp);
        if (abs(preChar - (s[i] - 'a')) <= k){
            result = max(result, longestIdealStringHelper(s[i] - 'a', i + 1, s, k, dp) + 1);
        }
        
        return dp[preChar][i] = result;
    }
};