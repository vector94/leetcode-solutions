class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digits;

        while (num){
            digits.push_back(num % 10);
            num /= 10;
        }

        for (int i = digits.size() - 1; i >= 0; i--){
            if (digits[i] == 6){
                digits[i] = 9;
                break;
            }
        }

        int ans = 0;

        for (int i = digits.size() - 1; i >= 0; i--){
            ans *= 10;
            ans += digits[i];
        }

        return ans;
    }
};