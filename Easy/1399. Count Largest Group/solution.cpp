class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> groups;
        int maxSize = 0;
        for (int i = 1; i <= n; i++){
            int curSum = getSum(i);
            groups[curSum]++;
            maxSize = max(maxSize, groups[curSum]);
        }

        int ans = 0;
        for (auto it : groups){
            if (it.second == maxSize){
                ans++;
            }
        }

        return ans;
    }

private:
    int getSum(int n){
        int sum = 0;
        while (n){
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }
};