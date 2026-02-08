class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp1, mp2;
        bool ret = true;
        for (int i = 0; i < s.size(); i++){
            if (mp1.find(s[i]) == mp1.end() && mp2.find(t[i]) == mp2.end()){
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }
            else if (mp1.find(s[i]) != mp1.end() && mp2.find(t[i]) != mp2.end()){
                if (mp1[s[i]] != t[i] || mp2[t[i]] != s[i]){
                    ret = false;
                    break;
                }
            }
            else if (mp1.find(s[i]) != mp1.end()){
                if (mp1[s[i]] != t[i]){
                    ret = false;
                    break;
                }
                mp2[t[i]] = s[i];
            }
            else{
                if (mp2[t[i]] != s[i]){
                    ret = false;
                    break;
                }
                mp1[s[i]] = t[i];
            }
        }
        return ret;
    }
};