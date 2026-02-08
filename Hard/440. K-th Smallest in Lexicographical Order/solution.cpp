class Solution {
public:
    int findKthNumber(int n, int k) {
        return getKthNumber(1, k - 1, n);
    }

    int getKthNumber(int curNum, int k, int n){
        if (k == 0) return curNum;

        int cnt = countSteps(curNum, curNum + 1, n);
        if (cnt <= k){
            return getKthNumber(curNum + 1, k - cnt, n);
        }
        else{
            return getKthNumber(curNum * 10, k - 1, n);
        }
    }

    int countSteps(long long curNum, long long nextNum, int n){
        int steps = 0;

        while (curNum <= n){
            steps += min((long long)n + 1, nextNum) - curNum;
            curNum *= 10;
            nextNum *= 10;
        }

        return steps;
    }
};