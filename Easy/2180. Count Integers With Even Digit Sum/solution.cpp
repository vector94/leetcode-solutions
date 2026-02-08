class Solution {
public:
    
    bool check(int num){
        int sum = 0;
        while (num){
            sum += num % 10;
            num /= 10;
        }
        return (sum % 2 == 0);
    }
    
    int countEven(int num) {
        int result = 0;
        for (int i = 1; i <= num; i++){
            if (check(i)){
                result++;
            }
        }
        return result;
    }
};