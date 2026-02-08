class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);

        for (char ch : s){
            freq[ch - 'a']++;
        }

        int maxVowelCnt = 0;
        int maxConsonentCnt = 0;

        for (char ch = 'a'; ch <= 'z'; ch++){
            if (isVowel(ch)){
                maxVowelCnt = max(maxVowelCnt, freq[ch - 'a']);
            }
            else{
                maxConsonentCnt = max(maxConsonentCnt, freq[ch - 'a']);
            }
        }

        return maxVowelCnt + maxConsonentCnt;
    }

    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};