class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long x = 0;
        long long maxValue = 0;
        long long minValue = 0;

        for (int n : differences){
            x += n;
            maxValue = max(maxValue, x);
            minValue = min(minValue, x);
        }

        cout << maxValue << " " << minValue << endl;

        return max((long long)0, (upper - lower) - (maxValue - minValue) + 1);
    }
};