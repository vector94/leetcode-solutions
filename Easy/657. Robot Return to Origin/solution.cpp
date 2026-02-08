class Solution {
public:
    bool judgeCircle(string moves) {
        int u, d, l, r;
        u = d = l = r = 0;
        for (char ch : moves){
            if (ch == 'U')      u++;
            else if (ch == 'D') d++;
            else if (ch == 'L') l++;
            else if (ch == 'R') r++;
        }
        if (u == d  && l == r){
            return true;
        }
        else{
            return false;
        }
    }
};