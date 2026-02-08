class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return solve(finish, limit, s) - solve(start - 1, limit, s);
    }
    
    long long solve(long long n, int limit, string s){
        if (n == 0) return 0;

        long long sVal = stoll(s);
        if (n < sVal)   return 0;

        vector<int> digits;
        long long temp = n;
        while (temp){
            digits.push_back(temp % 10);
            temp /= 10;
        }

        reverse(digits.begin(), digits.end());

        vector<vector<long long>> dp(2, vector<long long>(digits.size(), -1));
        
        return cal(0, 0, digits, limit, s, dp);
    }

    long long cal(
        int isSmall, int pos, 
        vector<int>& digits, int maxLimit, string& s,
        vector<vector<long long>>& dp
    ) {
        if (pos == digits.size()){
            return 1;
        }

        if (dp[isSmall][pos] != -1) {
            return dp[isSmall][pos];
        }

        int suffixPos = pos - (digits.size() - s.length());
        bool isSuffixPosition = suffixPos >= 0;

        long long ret = 0;
        int upperLimit = isSmall ? maxLimit : min(maxLimit, digits[pos]);

        if (isSuffixPosition) {
            int requiredDigit = s[suffixPos] - '0';
            
            if (requiredDigit <= upperLimit) {
                int newIsSmall = isSmall || (requiredDigit < digits[pos]);
                ret += cal(newIsSmall, pos + 1, digits, maxLimit, s, dp);
            }
        } 
        else {
            for (int d = 0; d <= upperLimit; d++) {
                int newIsSmall = isSmall || (d < digits[pos]);
                ret += cal(newIsSmall, pos + 1, digits, maxLimit, s, dp);
            }
        }
        
        return dp[isSmall][pos] = ret;
    }
};