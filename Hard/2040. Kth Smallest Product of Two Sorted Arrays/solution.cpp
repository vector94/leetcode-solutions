class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10;
        long long right = 1e10;
        long long ans;

        while (left <= right){
            long long mid = (left + right) / 2;

            long long cnt = getProductCount(nums1, nums2, mid);
            
            if (cnt >= k){
                ans = mid;
                right = mid - 1;
            } 
            else{
                left = mid + 1;
            }
        }

        return ans;
    }

    long long getProductCount(vector<int>& nums1, vector<int>& nums2, long long target){
        long long cnt = 0;

        for (int i = 0; i < nums1.size(); i++){
            if (nums1[i] > 0){
                int left = 0;
                int right = nums2.size() - 1;
                long long curCnt = 0;

                while (left <= right){
                    int mid = (left + right) / 2;
                    if ((long long)nums1[i] * nums2[mid] <= target){
                        curCnt = mid + 1;
                        left = mid + 1;
                    }
                    else{
                        right = mid - 1;
                    }
                }

                cnt += curCnt;
            }
            else if (nums1[i] < 0){
                int left = 0;
                int right = nums2.size() - 1;
                long long curCnt = 0;

                while (left <= right){
                    int mid = (left + right) / 2;

                    if ((long long)nums1[i] * nums2[mid] <= target){
                        right = mid - 1;
                        curCnt = nums2.size() - mid;
                    }
                    else{
                        left = mid + 1;
                    }
                }

                cnt += curCnt;
            }
            else{
                if (target >= 0){
                    cnt += nums2.size();
                }
            }
        }

        return cnt;
    }
};