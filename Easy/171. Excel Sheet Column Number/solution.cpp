class Solution {
public:
    long long titleToNumber(string columnTitle) {
        long long result = 0;
        long long pow = 1;
        
        for (int i = columnTitle.size() - 1; i >= 0; i--){
            result += pow * (columnTitle[i] - 'A' + 1);
            pow *= 26;
        }
        
        return result;
    }
};