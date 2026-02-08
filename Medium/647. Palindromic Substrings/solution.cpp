
class Solution {
public:
    
    void countHelper(string &s, int left, int right, int &count){
        for (int i = left, j = right; i >= 0 && j < s.size(); i--, j++){
            if (s[i] == s[j]){
                count++;
            }
            else{
                break;
            }
        }
    }
    
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++){
            countHelper(s, i, i, count);
            countHelper(s, i, i + 1, count);
        }
        return count;
    }
};

        
