class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<int> F(31, 0);
        F[0] = 1;

        for (int i = 1; i <= 30; i++){
            F[i] = 2 * F[i - 1] + 1;
        }

        int sign = 1;
        int result = 0;

        for (int i = 30; i >= 0; i--){
            int ithBit = (1 << i) & n;
            if (ithBit == 0) continue;

            result += (F[i] * sign);

            sign *= (-1);
        }

        return result;
    }
};