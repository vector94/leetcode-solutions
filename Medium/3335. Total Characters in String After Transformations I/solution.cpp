class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        long long MOD = 1e9 + 7;
        vector<long long> freq(30, 0);

        for (char ch : s){
            freq[ch - 'a']++;
        }

        while (t--){
            int zFreq = freq[25];
            freq[25] = 0;

            for (char ch = 'y'; ch >= 'a'; ch--){
                int idx = ch - 'a';
                if (freq[idx] == 0) continue;
                
                freq[idx + 1] += freq[idx];
                freq[idx + 1] %= MOD;
                freq[idx] = 0;
            }

            if (zFreq > 0){
                freq[0] += zFreq;
                freq[0] %= MOD;
                freq[1] += zFreq;
                freq[1] %= MOD;
            }

        }

        int result = 0;
        for (char ch = 'a'; ch <= 'z'; ch++){
            result += freq[ch - 'a'];
            result %= MOD;
        }

        return result;
    }
};