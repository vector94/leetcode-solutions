class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> v;
        while (n){
            int rem = n % 10;
            n /= 10;
            if (rem != 0)   v.push_back(rem);
        }

        long long x = 0;
        long long sum = 0;
        for (int i = v.size() - 1; i >= 0; i--){
            x *= 10;
            x += v[i];
            sum += v[i];
        }

        return x * sum;
    }
};