class Solution {
public:
    int maxPower(string s) {
        int cnt = 1;
        int result = 1;
        
        for (int i = 1; i < s.size(); i++){
            if (s[i] == s[i - 1]){
                cnt++;
            }
            else{
                result = max(result, cnt);
                cnt = 1;
            }
        }
        
        result = max(result, cnt);
        return result;
    }
};