class Solution {
public:
    
    void backtrack(long long &num, int &low, int &high, vector<int> &result){
        if (num > high) return;
        
        if (low <= num && num <= high){
            result.push_back(num);
        }
        
        if (num == 0){
            for (int i = 1; i <= 9; i++){
                num = i;
                backtrack(num, low, high, result);
                num = 0;
            }
        }
        else{
            int pre = num % 10;
            if (pre < 9){
                num = num * 10 + (pre + 1);
                backtrack(num, low, high, result);
                num /= 10;
            }
        }
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        long long num = 0;
        
        backtrack(num, low, high, result);
        
        sort(result.begin(), result.end());
        
        return result;
    }
};