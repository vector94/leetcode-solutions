class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;
        
        while (i < j && s[i] == s[j]){
            char leftChar = s[i];
            char rightChar = s[j];
            while (s[i] == rightChar && i <= j){
                i++;
            }
            
            while (s[j] == leftChar && i <= j){
                j--;
            }
        }
        
        return j - i + 1;
    }
};
