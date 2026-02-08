class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 0;
        long long right = 10000000;
        int ans;

        while (left <= right){
            long long mid = (left + right) / 2;

            if (check(mid, candies, k)){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return ans;
    }

    bool check(long long n, vector<int>& candies, long long k){
        if (n == 0) return true;
        
        long long total = 0;
        for (int c : candies){
            total += c / n;
        }

        return total >= k;
    }
};