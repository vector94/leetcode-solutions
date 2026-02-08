class Solution {
public:
    #define ll long long
    inline ll big_mod(ll a, ll p, ll m){
        ll res = 1 % m, x = a % m;
        while (p){
            if (p & 1) res = (res * x) % m;
            x = (x * x) % m, p >>= 1;
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;

        sort(nums.begin(), nums.end());
        
        int ans = 0;
        int r = nums.size() - 1;
        for (int l = 0; l < nums.size(); l++){
            while (r >= l && nums[r] + nums[l] > target){
                r--;
            }

            if (r < l)  break;

            ans += big_mod(2, r - l , mod);
            ans %= mod;
        }

        return ans;

    }
};