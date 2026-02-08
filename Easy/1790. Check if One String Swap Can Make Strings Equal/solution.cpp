class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        string x = s1;
        string y = s2;

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        if (x != y) return false;

        int diff = 0;
        for (int i = 0; i < s1.size(); i++){
            if (s1[i] != s2[i]) diff++;
        }

        return diff <= 2;
    }
};