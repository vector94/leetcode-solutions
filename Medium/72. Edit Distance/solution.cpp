class Solution {
public:
    
    int minDistanceHelper(int i, int j, string &word1, string &word2, vector<vector<int> > &dp){
        if (i == word1.size() || j == word2.size()){
            return (word1.size() - i) + (word2.size() - j);
        }
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int result = 0;
        
        if (word1[i] == word2[j]){
            result = minDistanceHelper(i + 1, j + 1, word1, word2, dp);
        }
        else{
            result = 1 + minDistanceHelper(i, j + 1, word1, word2, dp);
            result = min(result, 1 + minDistanceHelper(i + 1, j, word1, word2, dp));
            result = min(result, 1 + minDistanceHelper(i + 1, j + 1, word1, word2, dp));
        }
        
        return dp[i][j] = result;
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int> > dp(m, vector<int> (n, -1));
        
        return minDistanceHelper(0, 0, word1, word2, dp);
    }
};