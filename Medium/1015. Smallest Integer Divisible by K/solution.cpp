class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int n = 0;
        int length = 0;
        for (int i = 1; i <= k; i++){
            n = n * 10 + 1;
            length++;
            n %= k;
            if (n == 0){
                return length;
            }
        }
        return -1;
    }
};