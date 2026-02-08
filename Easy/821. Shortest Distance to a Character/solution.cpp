class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int len = s.size();
        vector<int> l(len), r(len);
        int pre = -1e6;
        for (int i = 0; i < len; i++){
            if (s[i] == c){
                pre = i;
            }
            l[i] = pre;
        }
        int next = 1e6;
        for (int i = len - 1; i >= 0; i--){
            if (s[i] == c){
                next = i;
            }
            r[i] = next;
        }
        vector<int> ret(len);
        for (int i = 0; i < len; i++){
            ret[i] = min(i - l[i], r[i] - i);
        }
        return ret;
    }
};