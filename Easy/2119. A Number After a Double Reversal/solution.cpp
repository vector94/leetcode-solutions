class Solution {
public:
    bool isSameAfterReversals(int n) {
        int num = n;
        int r1 = 0;
        while (num){
            r1 = r1 * 10 + num % 10;
            num /= 10;
        }
        int r2 = 0;
        while (r1){
            r2 = r2 * 10 + r1 % 10;
            r1 /= 10;
        }
        return r2 == n;
    }
};