class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int N = nums.size();
        long long sum = 0;
        long long ans = 0;

        int left = 0;
        for (int right = 0; right < N; right++){
            sum += nums[right];
            
            if (sum * (right - left + 1) < k){
                ans += right - left + 1;
            }
            else{
                while (left <= right){
                    sum -= nums[left];
                    left++;
                    if (sum * (right - left + 1) < k){
                        break;
                    }
                }
                ans += right - left + 1;
            }
        }

        return ans;
    }
};