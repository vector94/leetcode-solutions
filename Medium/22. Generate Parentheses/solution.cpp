class Solution {
public:
    vector<string> result;
    string s = "";
    void generate(int cntOpen, int cntClose, int n, string s){
        if (cntOpen == cntClose && cntOpen == n){
            result.push_back(s);
            return;
        }
        if (cntOpen < n){
            s.push_back('(');
            generate(cntOpen + 1, cntClose, n, s);
            s.pop_back();
        }
        if (cntClose < cntOpen){
            s.push_back(')');
            generate(cntOpen, cntClose + 1, n, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        generate(0, 0, n, s);
        return result;
    }
};