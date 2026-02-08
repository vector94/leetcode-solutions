class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long result = 0;

        for (int i = max(0, n - 2 * limit); i <= min(n, limit); i++){
            int N = n - i;

            long long minCandy = max(0, N - limit);
            long long maxCandy = min(N, limit);

            result += maxCandy - minCandy + 1;
        }

        return result;
    }
};