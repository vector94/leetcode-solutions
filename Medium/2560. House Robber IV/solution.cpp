class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        vector<int> sortedNums = nums;

        sort(sortedNums.begin(), sortedNums.end());
        
        int N = nums.size();
        int left = 0;
        int right = N - 1;

        int ans = sortedNums[right];

        while (left <= right){
            int mid = (left + right) / 2;

            if (check(nums, k, sortedNums[mid])){
                ans = sortedNums[mid];
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return ans;
    }

    bool check(vector<int>& nums, int k, int c){
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] <= c){
                cnt++;
                i++;
            }
        }

        return cnt >= k;
    }
};