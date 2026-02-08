class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        bool flag = true;
        for (auto x : s){
            if (x == '(' || x == '{' || x == '['){
                v.push_back(x);
            }
            else if (x == ')'){
                if (v.empty() || v.back() != '('){
                    flag = false;
                    break;
                }
                else{
                    v.pop_back();
                }
            }
            else if (x == '}'){
                if (v.empty() || v.back() != '{'){
                    flag = false;
                    break;
                }
                else{
                    v.pop_back();
                }
            }
            else if (x == ']'){
                if (v.empty() || v.back() != '['){
                    flag = false;
                    break;
                }
                else{
                    v.pop_back();
                }
            }
        }
        if (!v.empty()){
            flag = false;
        }
        return flag;
    }
};