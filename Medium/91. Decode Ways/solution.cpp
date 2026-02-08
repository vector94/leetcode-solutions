class Solution {
public:
    
    int numDecodingsHelper(int index, string &s, vector<int> &dp){
        if (index == s.size())  return 1;
        if (dp[index] != -1)    return dp[index];
        if (s[index] == '0')    return dp[index] = 0;
        
        int result = numDecodingsHelper(index + 1, s, dp);
        if (index + 1 < s.size() && stoi(s.substr(index, 2)) <= 26){
            result += numDecodingsHelper(index + 2, s, dp);
        }
        
        return dp[index] = result;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return numDecodingsHelper(0, s, dp);
    }
};