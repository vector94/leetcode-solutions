class Solution {
public:
    bool isHappy(int n) {
        int trial = 1e4;
        bool ret = false;
        while (trial--){
            int cur = 0;
            while (n){
                cur += (n % 10) * (n % 10);
                n /= 10;
            }
            if (cur == 1){
                ret = true;
                break;
            }
            n = cur;
        }
        return ret;
    }
};