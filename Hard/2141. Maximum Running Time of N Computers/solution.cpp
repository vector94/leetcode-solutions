class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = 0;
        long long sum = 0;

        for (int b : batteries){
            sum += b;
        }

        long long right = sum / n;
        long long ans;

        while (left <= right){
            long long mid = (left + right) / 2;
            if (check(n, batteries, mid)){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return ans;
    }

    bool check(int n, vector<int>& batteries, long long time){
        long long need = 0;

        for (int b : batteries){
            need += min(time, (long long)b);
        }

        return need >= time * n;
    }
};