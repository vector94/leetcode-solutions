class Solution {
public:
    int myAtoi(string s) {
        long long int num = 0;
        int len = s.length();
        int idx = 0;
        bool here = false;
        while (s[idx] == ' '){
            idx++;
            here = true;
        }
        bool neg = false;
        if (s[idx] == '-' || s[idx] == '+'){
            if (s[idx] == '-'){
                neg = true;
            }
            idx++;
        }
        for (int i = idx; i < len; i++){
            if (!isdigit(s[i])){
                break;
            }
            num = num * 10 + (int)(s[i] - '0');
            if (num > 1e10){
                break;
            }
        }
        if (neg){
            num = num * (-1);
        }
        int ret;
        if (num < INT_MIN){
            ret = INT_MIN;
        }
        else if (num > INT_MAX){
            ret = INT_MAX;
        }
        else{
            ret = num;
        }
        return ret;
    }
};