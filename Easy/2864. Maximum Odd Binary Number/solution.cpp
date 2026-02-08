class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int zero, one;
        zero = one = 0;
        
        for (char ch : s){
            if (ch == '0')  zero++;
            else            one++;
        }
        
        string result = "";
        while (one > 1){
            result.push_back('1');
            one--;
        }
        while (zero > 0){
            result.push_back('0');
            zero--;
        }
        result.push_back('1');
        
        return result;
    }
};