class Solution {
public:
    
    void solve(int curNum, int curDigit, int n, int k, vector<int> &result){
        if (curDigit == n){
            result.push_back(curNum);
            return;
        }
        if (curDigit == 0){
            for (int num = 1; num <= 9; num++){
                solve(num, 1, n, k, result);
            }
        }
        else{
            long lastNum = curNum % 10;
            if (lastNum + k <= 9){
                solve(curNum * 10 + lastNum + k, curDigit + 1, n, k, result);
            }
            if (lastNum - k >= 0 && k != 0){
                solve(curNum * 10 + lastNum - k, curDigit + 1, n, k, result);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        solve(0, 0, n, k, result);
        return result;
    }
};