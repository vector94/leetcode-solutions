class Solution {
public:
    
    int countVowelStringsHelper(int cur, int cnt){
        if (cnt == 0)   return 1;
        if (cur > 5)    return 0;
        
        return countVowelStringsHelper(cur, cnt - 1) + countVowelStringsHelper(cur + 1, cnt);
    }
    
    int countVowelStrings(int n) {
        return countVowelStringsHelper(1, n);
    }
};