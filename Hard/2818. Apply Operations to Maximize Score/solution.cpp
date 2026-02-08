class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> score(N);
        vector<int> primes = genPrime();

        for (int i = 0; i < N; i++){
            score[i] = getScore(nums[i], primes);
        }

        vector<long long> prev(N, -1);
        stack<long long> myStack;

        for (int i = 0; i < N; i++){
            while (!myStack.empty() && score[myStack.top()] < score[i]){
                myStack.pop();
            }
            if (!myStack.empty()){
                prev[i] = myStack.top();
            }
            myStack.push(i);
        }

        vector<long long> subarrayCount(N, -1);
        myStack = stack<long long>();

        for (int i = N - 1; i >= 0; i--){
            while (!myStack.empty() && score[myStack.top()] <= score[i]){
                myStack.pop();
            }

            if (myStack.empty()){
                subarrayCount[i] = (N - i) * (i - prev[i]);
            }
            else{
                subarrayCount[i] = (myStack.top() - i) * (i - prev[i]);
            }

            myStack.push(i);
        }

        // for (int i = 0; i < N; i++){
        //     cout << subarrayCount[i] << " ";
        // }
        // cout << endl;

        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < N; i++){
            maxHeap.push({nums[i], i});
        }

        long long mod = 1e9 + 7;
        long long result = 1;
        while (k > 0){
            long long num = maxHeap.top().first;
            long long index = maxHeap.top().second;
            long long count = subarrayCount[index];

            maxHeap.pop();

            if (k >= count){
                result = result * bigMod(num, count, mod);
                result %= mod;
                k -= count;
            }
            else{
                result = result * bigMod(num, k, mod);
                result %= mod;
                k = 0;  
            }
        }

        return result;
    }


    int getScore(int num, vector<int>& primes){
        int sqrtN = sqrt(num);
        int score = 0;

        for (int i = 0; primes[i] <= sqrtN; i++){
            if (num % primes[i] == 0){
                score++;

                while (num % primes[i] == 0){
                    num /= primes[i];
                }

                sqrtN = sqrt(num);
            }
        }

        if (num > 1){
            score++;
        }

        return score;
    }

    vector<int> genPrime(){
        vector<int> primes;
        int N = 1e5;
        vector<bool> sieve(N + 5, true);
        int sqrtN = sqrt(N);

        for (int i = 3; i <= sqrtN; i+= 2){
            if (sieve[i]){
                for (int j = i * i; j <= N; j += 2 * i){
                    sieve[j] = false;
                }
            }
        }
        primes.push_back(2);

        for (int i = 3; i <= N; i += 2){
            if (sieve[i]){
                primes.push_back(i);
            }
        }

        return primes;
    }

    long long bigMod(long long a, long long p, long long m){
        long long res = 1 % m, x = a % m;
        while (p){
            if (p & 1) res = (res * x) % m;
            x = (x * x) % m, p >>= 1;
        }
        return res;
    }

};