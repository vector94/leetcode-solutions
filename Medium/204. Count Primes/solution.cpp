const int nax = 5e6 + 5;
class Solution {
public:
    bool prime[nax];
    int countPrimes(int n) {
        if (n <= 3){
            if (n <= 2){
                return 0;
            }
            return 1;
        }
        for (int i = 3; i <= sqrt(n); i += 2){
            if (!prime[i]){
                for (int j = i * i; j <= n; j += 2 * i){
                    prime[j] = true;
                }
            }
        }
        int ret = 1;
        for (int i = 3; i < n; i += 2){
            if (!prime[i]){
                ret++;
            }
        }
        return ret;
    }
};