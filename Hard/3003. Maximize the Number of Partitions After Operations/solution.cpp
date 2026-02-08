class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long, int> dp;

        return solve(0, 0, 1, s, k, dp) + 1;
    }

    int solve(int uniqueChar, int idx, int canChange, string &s, int k, unordered_map<long long, int>& dp){
        if (idx == s.size())    return 0;

        long long key = ((long long)idx << 27) | (uniqueChar << 1) | canChange;
        if (dp.find(key) != dp.end()){
            return dp[key];
        }

        int ret = 0;
        int curCharIdx = s[idx] - 'a';


        int curUniqueChar = uniqueChar | (1 << curCharIdx);
        int curUniqueCharCnt = __builtin_popcount(curUniqueChar);

        if (curUniqueCharCnt > k){
            ret = max(ret, 1 + solve(1 << curCharIdx, idx + 1, canChange, s, k, dp));
        }
        else{
            ret = max(ret, solve(curUniqueChar, idx + 1, canChange, s, k, dp));
        }

        if (canChange){
            for (int i = 0; i < 26; i++){
                if (i == curCharIdx) continue;
                
                curUniqueChar = uniqueChar | (1 << i);
                curUniqueCharCnt = __builtin_popcount(curUniqueChar);

                if (curUniqueCharCnt > k){
                    ret = max(ret, 1 + solve(1 << i, idx + 1, 0, s, k, dp));
                }
                else{
                    ret = max(ret, solve(curUniqueChar, idx + 1, 0, s, k, dp));
                }

            }
        }

        return dp[key] = ret;
    }
};