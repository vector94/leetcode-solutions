int f1(char s){
    if (s == 'I')   return 1;
    else if (s == 'V')  return 5;
    else if (s == 'X')  return 10;
    else if (s == 'L')  return 50;
    else if (s == 'C')  return 100;
    else if (s == 'D')  return 500;
    else if (s == 'M')  return 1000;
    return 0;
}

int f2(string s){
    if (s == "IV")  return 4;
    else if (s == "IX") return 9;
    else if (s == "XL") return 40;
    else if (s == "XC") return 90;
    else if (s == "CD") return 400;
    else if (s == "CM") return 900;
    return 0;
}

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        int len = s.length();
        for (int i = 0; i < len; i++){
            if (s[i] == 'I' && i + 1 < len && (s[i + 1] == 'V' || s[i + 1] == 'X')){
                ret += f2(s.substr(i, 2));
                i++;
            }
            else if (s[i] == 'X' && i + 1 < len && (s[i + 1] == 'L' || s[i + 1] == 'C')){
                ret += f2(s.substr(i, 2));
                i++;
            }
            else if (s[i] == 'C' && i + 1 < len && (s[i + 1] == 'D' || s[i + 1] == 'M')){
                ret += f2(s.substr(i, 2));
                i++;
            }
            else{
                ret += f1(s[i]);
            }
            cout << i << " " << ret << endl;
        }
        return ret;
    }
};