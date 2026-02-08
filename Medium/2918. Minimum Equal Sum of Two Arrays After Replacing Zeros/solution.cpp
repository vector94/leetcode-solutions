class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1, sum2;
        sum1 = sum2 = 0;
        bool zeroIdx1, zeroIdx2;
        zeroIdx1 = zeroIdx2 = false;

        for (int i = 0; i < nums1.size(); i++){
            if (nums1[i] == 0){
                nums1[i] = 1;
                zeroIdx1 = true;
            };

            sum1 += nums1[i];
        }
        for (int i = 0; i < nums2.size(); i++){
            if (nums2[i] == 0){
                nums2[i] = 1;
                zeroIdx2 = true;
            }
            sum2 += nums2[i];
        }
        
        cout << sum1 << " " << sum2 << endl;

        if (sum1 == sum2){
            return sum1;
        }
        if (sum1 > sum2 && zeroIdx2){
            return sum1;
        }
        if (sum2 > sum1 && zeroIdx1){
            return sum2;
        }

        return -1;
    }
};