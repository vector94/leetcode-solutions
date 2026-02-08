class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for (auto x : s){
            if (isalnum(x)){
                temp += tolower(x);
            }
        }
        int len = temp.length();
        for (int i = 0, j = len - 1; i < len / 2; i++, j--){
            if (temp[i] != temp[j]){
                return false;
            }
        }
        return true;
    }
};