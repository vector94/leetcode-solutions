class Solution {
public:
    bool vowelCheck(char ch){
        return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    bool halvesAreAlike(string s) {
        int cnt1, cnt2;
        cnt1 = cnt2 = 0;
        for (int i = 0; i < s.size(); i++){
            if (vowelCheck(s[i])){
                if (i < s.size() / 2) cnt1++;
                else cnt2++;
            }
        }
        return (cnt1 == cnt2);
    }
};