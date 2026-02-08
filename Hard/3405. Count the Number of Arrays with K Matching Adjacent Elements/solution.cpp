class Solution {
    #define ll  long long int
public:
    // (n - 1) C k * m * (m - 1) ^ (n - k - 1)

    int countGoodArrays(int n, int m, int k) {
        long long mod = 1e9 + 7;

        long long diff = getFactorial(k, mod) * getFactorial((n - 1) - k, mod);
        long long modInvDiff = mod_inv(diff, mod);

        long long ret = getFactorial(n - 1, mod) * modInvDiff;
        ret %= mod;
        ret *= m;
        ret %= mod;

        ret *= big_mod(m - 1, n - k - 1, mod);
        ret %= mod;

        return ret;
    }

    long long getFactorial(int a, int mod){
        long long ret = 1;
        for (int i = 2; i <= a; i++){
            ret *= i;
            ret %= mod;
        }

        return ret;
    }

    inline ll big_mod(ll a, ll p, ll m){
        ll res = 1 % m, x = a % m;
        while (p){
            if (p & 1) res = (res * x) % m;
            x = (x * x) % m, p >>= 1;
        }
        return res;
    }

    ll ext_gcd(ll A, ll B, ll *X, ll *Y ){
        ll x2, y2, x1, y1, x, y, r2, r1, q, r;
        x2 = 1, y2 = 0;
        x1 = 0, y1 = 1;
        for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
            q = r2 / r1, r = r2 % r1;
            x = x2 - (q * x1), y = y2 - (q * y1);
        }
        *X = x2; *Y = y2;
        return r2;
    }

    inline ll mod_inv(ll a, ll m){
        ll x, y;
        ext_gcd(a, m, &x, &y);
        x %= m;
        if ( x < 0 ) x += m;
        return x;
    }
};
