class Solution {
public:

    int upperCount(string word){
        int cnt = 0;
        for (char ch : word){
            if (isupper(ch)){
                cnt++;
            }
        }
        return cnt;
    }

    bool detectCapitalUse(string word) {
        int upperCnt = upperCount(word);
        if (upperCnt == word.size() || upperCnt == 1 && isupper(word[0]) || upperCnt == 0){
            return true;
        }
        return false;
    }
};