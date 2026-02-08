class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.length();
        vector<string> ret;
        set<string> ST;
        for (int i = 0; i <= (1 << n) - 1; i++){
            string cur;
            for (int j = 0; j < n; j++){
                if (i & (1 << j)){
                    if (isdigit(s[j])){
                        cur += s[j];
                    }
                    else if (isupper(s[j])){
                        cur += tolower(s[j]);
                    }
                    else{
                        cur += toupper(s[j]);
                    }
                }
                else{
                    cur += s[j];
                }
            }
            ST.insert(cur);
        }
        for (auto it : ST){
            ret.push_back(it);
        }
        return ret;
    }
};