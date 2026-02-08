class Solution {
public:
    long long int reverseBits(long long int n) {
        long long int ret = 0;
        string s;
        while (n){
            if (n % 2 == 0){
                s += '0';
            }
            else {
                s += '1';
            }
            n /= 2;
        }
        while (s.size() < 32){
            s += '0';
        }
        cout << s << endl;
        long long int p = 1;
        for (int i = 31; i >= 0; i--){
            ret += (s[i] - '0') * p;
            p *= 2;
        }
        return ret;
    }
};