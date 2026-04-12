class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;

        while (n){
            if (n % 2 == prev)  return false;
            prev = n % 2;
            n /= 2;
        }

        return true;
    }   
};