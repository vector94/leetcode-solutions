class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int n : nums){
            int cnt = digitCount(n);
            if (cnt % 2 == 0)   ans++;
        }

        return ans;
    }

    int digitCount(int num){
        int cnt = 0;
        while (num){
            cnt++;
            num /= 10;
        }

        return cnt;
    }
};