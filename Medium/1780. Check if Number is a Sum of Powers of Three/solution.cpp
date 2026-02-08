class Solution {
public:
    bool checkPowersOfThree(int n) {
        for (int i = 15; i >= 0; i--){
            int currentPow = customPow(3, i);
            if (currentPow <= n){
                n -= currentPow;
            }
        }

        return n == 0;
    }

    int customPow(int base, int exp){
        if (base == 0)  return 1;
        int ret = 1;
        for (int i = 1; i <= exp; i++){
            ret *= base;
        }
        return ret;
    }
};