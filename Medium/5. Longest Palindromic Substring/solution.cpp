class Solution {
public:
    string getPalindrome(int left, int right, string s){
        if (s[left] != s[right])    return "";
        while (left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s) {
        string result = s.substr(0, 1);
        for (int i = 0; i < s.size() - 1; i++){
            string p1 = getPalindrome(i, i, s);
            string p2 = getPalindrome(i, i + 1, s);
            if (result.size() < max(p1.size(), p2.size())){
                result = p1.size() > p2.size() ? p1 : p2;
            }
        }
        return result;
    }
};