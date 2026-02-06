class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int, int> myMap;

        for (int i = 0; i < points.size(); i++){
            myMap[points[i][1]]++;
        }

        long long total = 0;
        long long ans = 0;
        int mod = 1e9 + 7;
        for (auto it = myMap.begin(); it != myMap.end(); it++){
            long long cur = (long long) it -> second * (it -> second - 1) / 2;
            ans += total * cur;
            total += cur;
            ans %= mod;
        }

        return ans;
    }
};