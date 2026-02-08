class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> result;
        if (num % 3 == 0){
            result.push_back(num / 3 - 1);
            result.push_back(num / 3);
            result.push_back(num / 3 + 1);
        }
        return result;
    }
};