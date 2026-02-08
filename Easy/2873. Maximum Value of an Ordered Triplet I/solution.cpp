class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long score = 0;
        int N = nums.size();

        for (int i = 0; i < N; i++){
            for (int j = i + 1; j < N; j++){
                for (int k = j + 1; k < N; k++){
                    long long curScore = (long long)(nums[i] - nums[j]) * (long long) nums[k];
                    score = max(score, curScore);
                }
            }
        }

        return score;
    }
};