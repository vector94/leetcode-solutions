class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        int result = 0;
        while (n > 0){
            n -= i;
            if (n >= 0){
                result++;
            }
            i++;
        }
        return result;
    }
};