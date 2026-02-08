class Solution {
public:
    int minOperations(string s) {
        int ret;
        int c1, c2;
        c1 = c2 = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] - '0' != i % 2){
                c1++;
            }
            if (s[i] - '0' != ((i + 1) % 2)){
                c2++;
            }
        }
        ret = min(c1, c2);
        return ret;
    }
};