class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int N = nums.size();
        unordered_map<int, int> count;
        long long ans = 0;
        int pairs = 0;

        int left, right;
        left = right = 0;

        while (right < N){
            count[nums[right]]++;
            if (count[nums[right]] > 1)   pairs += count[nums[right]] - 1;

            if (pairs >= k){
                ans += N - right;

                while (true){
                    count[nums[left]]--;
                    pairs -= count[nums[left]];
                    left++;
                    
                    if (pairs >= k){
                        ans += N - right;
                    }
                    else{
                        break;
                    }
                }
            }

            right++;
        }

        return ans;
    }
};