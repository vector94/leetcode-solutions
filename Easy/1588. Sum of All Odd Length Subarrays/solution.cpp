class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int result = 0;
        for (int len = 1; len <= arr.size(); len += 2){
            int curSum = 0;
            for (int i = 0; i < arr.size(); i++){
                curSum += arr[i];
                if (i >= len - 1){
                    result += curSum;
                    curSum -= arr[i - len + 1];
                }
            }
        }
        return result;
    }
};