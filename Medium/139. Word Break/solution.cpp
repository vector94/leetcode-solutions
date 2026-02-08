class Solution {
public:
    
    bool wordBreakHelper(int index, string &s, unordered_map<string, bool> &inDict, vector<int> &dp){
        if (index == s.size())  return 1;
        
        if (dp[index] != -1)    return dp[index];
        
        int result = 0;
        
        string cur;
        for (int i = index; i < s.size(); i++){
            cur += s[i];
            if (inDict.find(cur) != inDict.end()){
                result |= wordBreakHelper(i + 1, s, inDict, dp);
            }
        }
        
        return dp[index] = result;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string, bool> inDict;
        for (auto s : wordDict){
            inDict[s] = true;
        }
        int n = s.size();
        vector<int> dp(n, -1);
        
        return (bool) wordBreakHelper(0, s, inDict, dp);
    }
};