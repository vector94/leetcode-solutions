class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int N = nums.size();
        vector<int> freq(N + 1, 0);

        for (int n : nums){
            freq[n]++;
        }

        vector<int> result(2);
        for (int i = 1; i <= N; i++){
            if (freq[i] == 2){
                result[0] = i;
            }
            else if (freq[i] == 0){
                result[1] = i;
            }
        }
        return result;
    }
};