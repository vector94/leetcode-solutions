class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)   return s;
        int cycleLen = 2 * numRows - 2;
        int len = s.length();
        string ret;
        for (int i = 0; i < numRows; i++){
            if (i == 0 || i == numRows - 1){
                int idx = i;
                while (idx < len){
                    ret += s[idx];
                    idx += cycleLen;
                }
                continue;
            }
            int idx = i;
            while (idx < len){
                ret += s[idx];
                int next = 2 * ((numRows - 1) - i);
                if (idx + next < len){
                    ret += s[idx + next];
                }
                idx += cycleLen;
            }
        }
        return ret;
    }
};