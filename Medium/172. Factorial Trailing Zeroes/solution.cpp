class Solution {
public:
    int trailingZeroes(int n) {
        int den = 5;
        int ret = 0;
        while (den <= n){
            ret += n / den;
            den *= 5;
        }
        return ret;
    }
};