class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int N = s.size();
        int MOD = 1e9 + 7;

        vector<int> prefixSum(N + 1, 0), digitCnt(N + 1, 0);
        vector<long long> nums(N + 1, 0);

        for (int i = 1; i <= N; i++){
            prefixSum[i] = prefixSum[i - 1] + s[i - 1] - '0';
            digitCnt[i] = digitCnt[i - 1] + ((s[i - 1] != '0') ? 1 : 0);

            if (s[i - 1] != '0'){
                nums[i] = nums[i - 1] * 10 + (s[i - 1] - '0');
                nums[i] %= MOD;
            }
            else{
                nums[i] = nums[i - 1];
            }
        }

        vector<long long> pows(N + 1, 1);
        for (int i = 1; i <= N; i++){
            pows[i] = (pows[i - 1] * 10) % MOD;
        }

        vector<int> results;

        for (int i = 0; i < queries.size(); i++){
            int l = queries[i][0] + 1;
            int r = queries[i][1] + 1;

            int cnt = digitCnt[r] - digitCnt[l - 1];
            long long x = ((nums[r] - ((nums[l - 1] * pows[cnt]) % MOD)) + MOD) % MOD;

            long long sum = prefixSum[r] - prefixSum[l - 1];

            long long result = (x * sum) % MOD;

            results.push_back((int)result);
        }

        return results;
    }
};