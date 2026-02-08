class Solution {
public:
    int longestPalindromeSubseq(int left, int right, string &s, vector<vector<int> > &dp){
        if (left == right)  return dp[left][right] = 1;
        if (left > right)   return 0;
        int &ret = dp[left][right];
        if (ret != -1)  return ret;
        if (s[left] == s[right]){
            ret = 2 + longestPalindromeSubseq(left + 1, right - 1, s, dp);
        }
        else{
            ret = max(  longestPalindromeSubseq(left + 1, right, s, dp), 
                        longestPalindromeSubseq(left, right - 1, s, dp));
        }
        return ret;
    } 

    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));
        int longestPalSubseq = longestPalindromeSubseq(0, s.size() - 1, s, dp);
        if (n - longestPalSubseq <= k){
            return true;
        }
        return false;
    }
};