class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) return vector<int> {0};
        vector<int> f(n + 1);
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i <= n; i++){
            f[i] = f[i >> 1] + (i % 2);
        }
        return f;
    }
};