class Solution {
public:
    long long reverse(long long x) {
        long long int ret = 0;
        bool neg = (x < 0);
        x = abs(x);
        while (x){
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        if (neg){
            ret *= (-1);
        }
        if (ret < INT_MIN || ret > INT_MAX){
            ret = 0;
        }
        return ret;
    }
};