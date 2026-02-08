class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> r;
        r.push_back(make_pair(1000, "M"));
        r.push_back(make_pair(900, "CM"));
        r.push_back(make_pair(500, "D"));
        r.push_back(make_pair(400, "CD"));
        r.push_back(make_pair(100, "C"));
        r.push_back(make_pair(90, "XC"));
        r.push_back(make_pair(50, "L"));
        r.push_back(make_pair(40, "XL"));
        r.push_back(make_pair(10, "X"));
        r.push_back(make_pair(9, "IX"));
        r.push_back(make_pair(5, "V"));
        r.push_back(make_pair(4, "IV"));
        r.push_back(make_pair(1, "I"));
        vector<int> v;
        int mul = 1;
        while (num){
            v.push_back(num % 10);
            num /= 10;
            mul *= 10;
        }
        mul /= 10;
        string ret = "";
        for (int i = v.size() - 1; i >= 0; i--){
            int x = v[i] * mul;
            mul /= 10;
            while (x){
                for (int i = 0; i < r.size(); i++){
                    if (r[i].first <= x){
                        ret += r[i].second;
                        x -= r[i].first;
                        break;
                    }
                }
            }
            num /= 10;
        }
        return ret;
    }
};