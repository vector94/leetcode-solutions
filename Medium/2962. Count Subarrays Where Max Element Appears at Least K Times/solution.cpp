class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        queue<int> myQueue;
        long long ans = 0;
        int N = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        
        for (int i = 0; i < N; i++){
            if (nums[i] == maxNum){
                myQueue.push(i);
            }
            while (myQueue.size() > k){
                myQueue.pop();
            }

            if (myQueue.size() == k){
                ans += myQueue.front() + 1;
            }
        }

        return ans;
    }
};