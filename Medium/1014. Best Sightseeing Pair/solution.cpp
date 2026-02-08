class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int curMax = values[0] - 1;
        int result = 0;
        for (int i = 1; i < values.size(); i++){
            result = max(result, values[i] + curMax);
            curMax = max(curMax - 1, values[i] - 1);
        }
        return result;
    }
};