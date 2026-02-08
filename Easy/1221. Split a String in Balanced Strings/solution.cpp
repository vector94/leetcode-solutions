class Solution {
public:
    int balancedStringSplit(string s) {
        int ret = 0;
        int cur = 0;
        for (int i = 0; i < s.length(); i++){
            if (i != 0 && cur == 0){
                ret++;
            }
            if (s[i] == 'L'){
                cur++;
            }
            else{
                cur--;
            }
        }
        return ret + 1;
    }
};