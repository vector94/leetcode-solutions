class Solution {
public:
    bool doesAliceWin(string s) {
        int vowelCnt = 0;
        for (char ch : s){
            if (isVowel(ch)){
                vowelCnt++;
            }
        }

        if (vowelCnt == 0)  return false;
        return true;
    }

    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};