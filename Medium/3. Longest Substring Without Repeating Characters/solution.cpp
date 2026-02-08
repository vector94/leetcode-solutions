class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> ST;
        int ret = 0;
        int l, r;
        l = r = 0;
        while (r < s.size()){
            if (ST.find(s[r]) == ST.end()){
                ST.insert(s[r]);
                r++;
            }
            else{
                while (ST.find(s[r]) != ST.end()){
                    ST.erase(s[l]);
                    l++;
                }
                ST.insert(s[r]);
                r++;
            }
            int cur = ST.size();
            ret = max(ret, cur);
        }
        return ret;
    }
};
