class Solution {
public:
    long long int titleToNumber(string s) {
        long long int ret = 0;
        long long int p = 1;
        for (int i = s.length() - 1; i >= 0; i--){
            ret += p * (s[i] - 'A' + 1);
            p *= 26;
        }
        return ret;
    }
};