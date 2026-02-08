class Solution {
public:
    int N;
    int digitSum;
    long long totalPerm = 0;
    int MOD = 1e9 + 7;
    long long fact[100], factInv[100];
    int freq[10];
    long long dp[10][50][400];

    long long power(long long a, long long b){
        if (b == 0) return 1;
        
        long long half = power(a, b / 2);
        long long ret = (half * half) % MOD;
        
        if (b & 1){
            ret = (ret * a) % MOD;
        }

        return ret;
    }

    int countBalancedPermutations(string num) {
        N = num.size();
        digitSum = 0;
        for (int i = 0; i < N; i++){
            int n = num[i] - '0';
            freq[n]++;
            digitSum += n;
        }

        if (digitSum % 2 != 0){
            return 0;
        }

        fact[0] = fact[1] = 1;
        for (int i = 2; i <= N; i++){
            fact[i] = (i * fact[i - 1]) % MOD;
        }

        for (int i = 0; i <= N; i++){
            factInv[i] = power(fact[i], MOD - 2) % MOD;
        }

        totalPerm = (fact[(N + 1) / 2] * fact[N / 2]) % MOD;
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0);
    }

    int solve(int digit, int evenIdxCnt, int evenSum){
        if (evenSum > digitSum / 2){
            return 0;
        }

        if (digit == 10){
            if (evenSum == digitSum / 2 && evenIdxCnt == (N + 1) / 2){
                return totalPerm;
            }
            return 0;
        }

        if (dp[digit][evenIdxCnt][evenSum] != -1){
            return dp[digit][evenIdxCnt][evenSum];
        }

        long long ret = 0;

        for (int i = 0; i <= min(freq[digit], (N + 1) / 2 - evenIdxCnt); i++){
            int evenCnt = i;
            int oddCnt = freq[digit] - i;

            long long div = (factInv[evenCnt] * factInv[oddCnt]) % MOD;
            
            long long curRet = solve(digit + 1, evenIdxCnt + evenCnt, evenSum + evenCnt * digit);
            ret += (curRet * div) % MOD;
            ret %= MOD;
        }

        return dp[digit][evenIdxCnt][evenSum] = ret;
    }
    
};