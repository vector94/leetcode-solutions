class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back() - nums[0];
        int result = high;

        while (low <= high){
            int mid = (low + high) / 2;

            // cout << low << " " << high << " " << mid << " " << check(mid, nums, p) << endl;

            if (check(mid, nums, p)){
                result = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return result;
    }

    bool check(int m, vector<int>& nums, int p){
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i + 1] - nums[i] <= m){
                cnt++;
                i++;
            }
        }

        return cnt >= p;
    }
};