class Solution {
public:
    bool detectCapitalUse(string word) {
        int UpperCase = 0;
        
        for (int i = 0; i < word.size(); i++){
            if (isupper(word[i]))   UpperCase++;
        }
        
        if (UpperCase == 0 || (UpperCase == 1 && isupper(word[0])) || UpperCase == word.size()){
            return true;
        }
        
        return false;
    }
};