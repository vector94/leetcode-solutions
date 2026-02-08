class Solution {
public:
    const long long mod = 1e9 + 7;
    long long countHomogenous(string s) {
        long long res = 0;
        for (int i = 0; i < s.length(); i++){
            long long cnt = 0;
            char cur = s[i];
            while (s[i] == cur){
                i++;
                cnt++;
            }
            i--;
            res += (cnt * (cnt + 1)) / 2;
            res %= mod;
        }
        return res;
    }
};