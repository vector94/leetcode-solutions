class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        vector<string> palindromes;
        string p;
        genPalindromes(0, n, k, p, palindromes);

        map<string, int> myMap;
        for (string p : palindromes){
            myMap[p]++;
            if (myMap[p] > 1)   cout << p << endl;
        }

        vector<long long> factorial(12);
        factorial[0] = 1;
        for (int i = 1; i <= 10; i++){
            factorial[i] = factorial[i - 1] * i;
        }

        set<vector<int>> uniqueDigitSets;
        for (int i = 0; i < palindromes.size(); i++){
            vector<int> digitCount(10, 0);
            for (char ch : palindromes[i]){
                digitCount[ch - '0']++;
            }
            uniqueDigitSets.insert(digitCount);
        }
        
        long long ans = 0;
        for (auto freq : uniqueDigitSets){
            ans += countValidPermutations(freq, n, factorial);
        }

        return ans;
    }

    long long countValidPermutations(vector<int>& freq, long long len, vector<long long>& factorial) {
        long long total = factorial[len];
        for (int i = 0; i < 10; i++) {
            total /= factorial[freq[i]];
        }
        
        if (freq[0] > 0) {
            vector<int> newFreq = freq;
            newFreq[0]--;
            
            long long invalid = factorial[len-1];
            for (int i = 0; i < 10; i++) {
                invalid /= factorial[newFreq[i]];
            }
            
            total -= invalid;
        }
        
        return total;
    }

    void genPalindromes(int idx, int n, int k, string p, vector<string>& palindromes){
        if (idx == n || idx == (n + 1) / 2){
            if (n == 1){
                long long num = stoll(p);
                if (num % k == 0){
                    palindromes.push_back(p);
                }
                return;
            }
            else{
                string prefix = p.substr(0, n / 2);
                reverse(prefix.begin(), prefix.end());

                long long num = stoll(p + prefix);
                if (num % k == 0){
                    palindromes.push_back(p + prefix);
                }
                return;
            }
        }
        if (idx == 0){
            for (char ch = '1'; ch <= '9'; ch++){
                p.push_back(ch);
                genPalindromes(idx + 1, n, k, p, palindromes);
                p.pop_back();
            }
        }
        else{
            for (char ch = '0'; ch <= '9'; ch++){
                p.push_back(ch);
                genPalindromes(idx + 1, n, k, p, palindromes);
                p.pop_back();
            }
        }
    }
};

