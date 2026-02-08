class Solution {
public:
    string longestPalindrome(string s) {
        string ret;
        int mx_len = 0;
        int len = s.size();
        for (int i = 0; i < len; i++){
            int cur = 1;
            int idx = i;
            for (int j = 1; i - j >= 0 && i + j < len; j++){
                if (s[i - j] == s[i + j]){
                    cur += 2;
                    idx = i - j;
                }
                else{
                    break;
                }
            }
            if (cur > mx_len){
                mx_len = cur;
                ret = s.substr(idx, cur);
            }
        }
        for (int i = 0; i < len; i++){
            int cur = 0;
            int idx;
            for (int j = 0; i - j >= 0 && i + j + 1 < len; j++){
                if (s[i - j] == s[i + j + 1]){
                    cur += 2;
                    idx = i - j;
                }
                else{
                    break;
                }
            }
            if (cur > mx_len){
                mx_len = cur;
                ret = s.substr(idx, cur);
            }
        }
        return ret;
    }
};