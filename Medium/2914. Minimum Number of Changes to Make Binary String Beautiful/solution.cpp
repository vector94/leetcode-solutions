class Solution {
public:
    int minChanges(string s) {
        int cnt = 1;
        int cur_char = s[0];
        int result = 0;

        for (int i = 1; i < s.size(); i++){
            if (s[i] == cur_char){
                cnt++;
                continue;
            }

            if (cnt % 2 == 0){
                cnt = 1;
                cur_char = s[i];
            }
            else{
                cnt++;
                result++;
            }
        }
        return result;
    }
};