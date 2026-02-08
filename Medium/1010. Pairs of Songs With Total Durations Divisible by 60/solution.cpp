class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remCount(60, 0);
        
        for (int t : time){
            remCount[t % 60]++;
        }
        
        int result = (remCount[0] * (remCount[0] - 1)) / 2 + (remCount[30] * (remCount[30] - 1)) / 2;
        cout << result << endl;
        for (int i = 1; i < 30; i++){
            result += remCount[i] * remCount[60 - i];
        }
        
        return result;
    }
};