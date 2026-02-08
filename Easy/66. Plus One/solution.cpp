class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; i--){
            if (i == digits.size() - 1){
                int sum = digits[i] + 1;
                ret.push_back(sum % 10);
                carry = sum / 10;
            }
            else{
                int sum = digits[i] + carry;
                ret.push_back(sum % 10);
                carry = sum / 10;
            }
        }
        if (carry != 0){
            ret.push_back(carry);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};