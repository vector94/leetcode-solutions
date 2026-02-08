class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0;
        long long curVal = 0;

        for (int i = s.size() - 1; i >= 0; i--){
            if (s[i] == '0'){
                ans++;
                continue;
            }

            if (ans > 30)   continue;
            long long nextVal = curVal + pow(2, ans);
            if (nextVal > k)    continue;

            curVal = nextVal;
            ans++;
        }

        return ans;
    }
};