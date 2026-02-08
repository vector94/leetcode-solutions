class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int N = nums.size();
        int ans = 0;
        int left = 0;
        int right = 0;

        int curSum = 0;
        int curXor = 0;

        while (right < N){
            curSum += nums[right];
            curXor ^= nums[right];

            if (curSum == curXor){
                ans = max(ans, right - left + 1);
                right++;  
            }
            else{
                // cout << "Right: " << right << endl;
                while (curSum != curXor){
                    // cout << "Left: " << left << " -> " << "Xor: " << curXor << ", Sum: " << curSum << endl;
                    curSum -= nums[left];
                    curXor ^= nums[left];
                    left++;
                }
                right++;
                // cout << "After Left: " << left << " -> " << "Xor: " << curXor << ", Sum: " << curSum << endl;
            }
        }

        return ans;
    }
};