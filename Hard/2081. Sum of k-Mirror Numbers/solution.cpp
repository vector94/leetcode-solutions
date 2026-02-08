class Solution {
public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        
        while (n){
            int L = 1;

            while (n){
                vector<long long> palindromes = genPalindromes(L);

                for (int i = 0; i < palindromes.size() && n; i++){
                    string baseK = getBaseK(palindromes[i], k);
                    if (checkPalindrome(baseK)){
                        sum += palindromes[i];
                        n--;
                    }
                }

                L++;
            }
        }

        return sum;
    }

    vector<long long> genPalindromes(int len){
        long long mid = (len + 1) / 2;
        long long minNum = pow(10, mid - 1);
        long long maxNum = pow(10, mid) - 1;

        vector<long long> palindromes;

        for (long long i = minNum; i <= maxNum; i++){
            string prefix = to_string(i);
            string suffix = prefix;
            reverse(suffix.begin(), suffix.end());

            if (len % 2 == 0){
                string x = prefix + suffix;
                palindromes.push_back(stoll(x));
            }
            else{
                string x = prefix + suffix.substr(1, suffix.size() - 1);
                palindromes.push_back(stoll(x));
            }
        }

        return palindromes;
    }

    string getBaseK(long long num, int k){
        string ret;

        while (num){
            ret.push_back(num % k + '0');
            num /= k;
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }

    bool checkPalindrome(string& num){
        int len = num.size();

        for (int i = 0; i < len / 2; i++){
            if (num[i] != num[(len - 1) - i]){
                return false;
            }
        }

        return true;
    }
};