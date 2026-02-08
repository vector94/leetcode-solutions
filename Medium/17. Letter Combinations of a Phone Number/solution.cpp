class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<char>v[10];
        v[2] = {'a', 'b', 'c'};
        v[3] = {'d', 'e', 'f'};
        v[4] = {'g', 'h', 'i'};
        v[5] = {'j', 'k', 'l'};
        v[6] = {'m', 'n', 'o'};
        v[7] = {'p', 'q', 'r', 's'};
        v[8] = {'t', 'u', 'v'};
        v[9] = {'w', 'x', 'y', 'z'};
        vector<string> ret;
        if (digits.size() == 1){
            for (int i = 0; i < v[digits[0] - '0'].size(); i++){
                string cur;
                cur.push_back(v[digits[0] - '0'][i]);
                ret.push_back(cur);
            }
        }
        else if (digits.size() == 2){
            for (int i = 0; i < v[digits[0] - '0'].size(); i++){
                for (int j = 0; j < v[digits[1] - '0'].size(); j++){
                    string cur;
                    cur.push_back(v[digits[0] - '0'][i]);
                    cur.push_back(v[digits[1] - '0'][j]);
                    ret.push_back(cur);
                }
            }
        }
        else if (digits.size() == 3){
            for (int i = 0; i < v[digits[0] - '0'].size(); i++){
                for (int j = 0; j < v[digits[1] - '0'].size(); j++){
                    for (int k = 0; k < v[digits[2] - '0'].size(); k++){
                        string cur;
                        cur.push_back(v[digits[0] - '0'][i]);
                        cur.push_back(v[digits[1] - '0'][j]);
                        cur.push_back(v[digits[2] - '0'][k]);
                        ret.push_back(cur);
                    }
                }
            }
        }
        else if (digits.size() == 4){
            for (int i = 0; i < v[digits[0] - '0'].size(); i++){
                for (int j = 0; j < v[digits[1] - '0'].size(); j++){
                    for (int k = 0; k < v[digits[2] - '0'].size(); k++){
                        for (int l = 0; l < v[digits[3] - '0'].size(); l++){
                            string cur;    
                            cur.push_back(v[digits[0] - '0'][i]);
                            cur.push_back(v[digits[1] - '0'][j]);
                            cur.push_back(v[digits[2] - '0'][k]);
                            cur.push_back(v[digits[3] - '0'][l]);
                            ret.push_back(cur);
                        }
                    }
                }
            }
        }
        return ret;
    }
};