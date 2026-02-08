class Solution {
public:
    int countGoodNumbers(long long n) {
        if (n == 1) return 5;
        long long mod = 1e9 + 7;

        long long odd = (n - 1) / 2 + 1;
        long long even = n / 2;

        return (big_mod(5, odd, mod) * big_mod(4, even, mod)) % mod;
    }

    long long big_mod(long long a, long long p, long long m){
        long long res = 1 % m, x = a % m;
        while (p){
            if (p & 1) res = (res * x) % m;
            x = (x * x) % m, p >>= 1;
        }
        return res;
    }
};