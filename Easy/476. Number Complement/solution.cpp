class Solution {
public:
    int findComplement(int num) {
        long long p = 1;
        int result = 0;
        
        while (num){
            if (num % 2 == 0){
                result += p;
            }
            num /= 2;
            p *= 2;
        }
        
        return result;
    }
};