class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();

        if (s == goal)  return true;

        for (int i = 0; i < n; i++){
            char ch = s[0];
            string sub = s.substr(1, n - 1);
            sub.push_back(ch);

            s = sub;

            if (s == goal)    return true;
        }

        return false;
    }
};