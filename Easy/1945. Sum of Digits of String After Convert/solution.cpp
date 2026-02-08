class Solution {
public:
    int getLucky(string s, int k) {
        int ret = 0;
        k--;
        for (char ch : s){
            int cur = (ch - 'a') + 1;
            while (cur){
                ret += cur % 10;
                cur /= 10;
            }
        }
        while (k--){
            int sum = 0;
            while (ret){
                sum += ret % 10;
                ret /= 10;
            }
            ret = sum;
        }
        return ret;
    }
};