class Solution {
public:
    int maxOperations(string s) {
        int preCnt, ans;
        preCnt = ans = 0;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '0'){
                ans += preCnt;
                while (i < s.size() && s[i] == '0'){
                    i++;
                }
                i--;
            }
            else{
                while (i < s.size() && s[i] == '1'){
                    preCnt++;
                    i++;
                }
                i--;
            }
        }

        return ans;
    }
};