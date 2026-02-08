class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;

        dfs(0, 0, n, result);

        return result;
    }

    void dfs(int idx, int curNum, int n, vector<int>& result){
        for (int i = 0; i <= 9; i++){
            if (i == 0 && idx == 0) continue;

            if (curNum * 10 + i <= n){
                curNum *= 10;
                curNum += i;
                result.push_back(curNum);
                dfs(idx + 1, curNum, n, result);
                curNum /= 10;
            }
        }
    }
};