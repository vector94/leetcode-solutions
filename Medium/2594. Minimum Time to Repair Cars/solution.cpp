class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = (long long)cars * (long long)cars * 100;
        long long ans;

        while (low <= high){
            long long mid = (low + high) / 2;
            if (check(ranks, cars, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }

    bool check(vector<int>& ranks, int cars, long long time){
        long long total = 0;

        for (int i = 0; i < ranks.size(); i++){
            total += sqrt(time / ranks[i]);
        }

        return total >= cars;
    }
};
