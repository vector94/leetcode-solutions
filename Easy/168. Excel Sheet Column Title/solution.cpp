class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while (n--){
            ret = (char)('A' + (n % 26)) + ret;
            n /= 26;
        }
        return ret;
    }
};