class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 && j >= 0){
            int sum = a[i] - '0' + b[j] - '0' + carry;
            carry = 0;
            if (sum == 0){
                ret += '0';
            }
            else if (sum == 1){
                ret += '1';
            }
            else if (sum == 2){
                ret += '0';
                carry = 1;
            }
            else{
                ret += '1';
                carry = 1;
            }
            i--;
            j--;
        }
        cout << ret << endl;
        while (i >= 0){
            int sum = a[i] - '0' + carry;
            carry = 0;
            if (sum == 0){
                ret += '0';
            }
            else if (sum == 1){
                ret += '1';
            }
            else if (sum == 2){
                ret += '0';
                carry = 1;
            }
            else{
                ret += '1';
                carry = 1;
            }
            i--;
        }
        while (j >= 0){
            int sum = b[j] - '0' + carry;
            carry = 0;
            if (sum == 0){
                ret += '0';
            }
            else if (sum == 1){
                ret += '1';
            }
            else if (sum == 2){
                ret += '0';
                carry = 1;
            }
            else{
                ret += '1';
                carry = 1;
            }
            j--;
        }
        if (carry){
            ret += '1';
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};