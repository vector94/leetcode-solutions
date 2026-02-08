class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> result;
        for (int i = 1; i <= n - 1; i++){
            if (checkNonZero(i) && checkNonZero(n - i)){
                result.push_back(i);
                result.push_back(n - i);
                break;
            }
        }

        return result;
    }

    bool checkNonZero(int n){
        while (n){
            if (n % 10 == 0)    return false;
            n /= 10;
        }

        return true;
    }
};