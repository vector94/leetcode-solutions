class Solution {
public:
    string robotWithString(string s) {
        int N = s.size();
        vector<char> minCharToLeft(N + 1);
        minCharToLeft[N] = 'z';
        for (int i = N - 1; i >= 0; i--){
            minCharToLeft[i] = min(s[i], minCharToLeft[i + 1]);
        }

        string t, p;
        for (int i = 0; i < N; i++){
            t.push_back(s[i]);

            while (!t.empty() && t.back() <= minCharToLeft[i + 1]){
                p.push_back(t.back());
                t.pop_back();
            }
        }

        while (!t.empty()){
            p.push_back(t.back());
            t.pop_back();
        }

        return p;
    }
};