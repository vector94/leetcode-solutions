class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        for (int i = s.length() - 1; i >= 0; i--){
            if (s[i] != ' '){
                int cnt = 0;
                while (i >= 0 && s[i] != ' '){
                    cnt++;
                    i--;
                }
                ret = cnt;
                break;
            }
        }
        return ret;
    }
};