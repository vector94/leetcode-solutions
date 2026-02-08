class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int N = stations.size();

        vector<long long> diffArray(N + 1, 0);
        for (int i = 0; i < N; i++){
            int left = max(0, i - r);
            int right = min(N, i + r + 1);
            diffArray[left] += stations[i];
            diffArray[right] -= stations[i];
        }

        long long left = 0;
        long long right = 1e12;
        long long result = 0;

        while (left <= right){
            long long mid = (left + right) / 2;

            if (check(mid, N, diffArray, r, k)){
                result = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return result;
    }

    bool check(long long power, int N, vector<long long> diffArray, int r, int k){
        long long curPower = 0;
        for (int i = 0; i < N; i++){
            curPower += diffArray[i];

            if (curPower >= power)  continue;

            long long diff = power - curPower;
            if (diff > k)   return false;

            curPower += diff;
            int right = min(N, i + 2 * r + 1);
            diffArray[right] -= diff;
            k -= diff;
        }

        return true;
    }
};