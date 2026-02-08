class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> result;
        
        if (finalSum % 2 != 0)  return result;
        
        for (long long i = 2; ; i += 2){
            if (finalSum - i <= i){
                result.push_back(finalSum);
                break;
            }
            result.push_back(i);
            finalSum -= i;
        }
        
        return result;
    }
};