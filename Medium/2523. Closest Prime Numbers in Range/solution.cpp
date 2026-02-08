class Solution {
public:
    vector<int> primes;
    void gen_prime(int left, int right){
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = left; i <= right; i++){
            if(isPrime[i]) primes.push_back(i);
        }
    }

    vector<int> closestPrimes(int left, int right) {
        gen_prime(left, right);

        int minDiff = 1000000;
        vector<int> result ({-1, -1});

        if (primes.size() < 2)  return result;

        for (int i = 0; i < primes.size() - 1; i++){
            if (left <= primes[i] && primes[i + 1] <= right && primes[i + 1] - primes[i] < minDiff){
                result = vector<int> ({primes[i], primes[i + 1]});
                minDiff = primes[i + 1] - primes[i];
            }
        }

        return result;
    }
};