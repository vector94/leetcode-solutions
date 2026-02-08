class Solution {
public:
    
    int dp[2][2][10];
    
    int solveHelper(int isStart, int isSmall, int index, vector<int> &digit, vector<int> &number){
        if (index == number.size())             return 1;
        if (dp[isStart][isSmall][index] != -1)  return dp[isStart][isSmall][index];
        
        int result = 0;
        
        if (isStart){
            
            result += solveHelper(1, 1, index + 1, digit, number);
            
            int limit = isSmall ? 9 : number[index];
            
            for (int i = 0; i < digit.size(); i++){
                if (digit[i] > limit)   break;
                result += solveHelper(0, isSmall | (digit[i] < number[index]), index + 1, digit, number);
            }
        }
        else{
            int limit = isSmall ? 9 : number[index];
            
            for (int i = 0; i < digit.size(); i++){
                if (digit[i] > limit)   break;
                result += solveHelper(isStart, isSmall | (digit[i] < number[index]), index + 1, digit, number);
            }
        }
        
        return dp[isStart][isSmall][index] = result;
    }
    
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> number;
        while (n){
            number.push_back(n % 10);
            n /= 10;
        }
        reverse(number.begin(), number.end());
        
        vector<int> digit;
        for (int i = 0; i < digits.size(); i++){
            digit.push_back(digits[i][0] - '0');
        }
        
        memset(dp, -1, sizeof(dp));
        
        return solveHelper(1, 0, 0, digit, number) - 1;
    }
};