class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();

        vector<long long> finishTime(n, 0);

        for (int i = 0; i < m; i++){
            finishTime[0] += 1LL * skill[0] * mana[i];

            for (int j = 1; j < n; j++){
                finishTime[j] = max(finishTime[j], finishTime[j - 1]) + 1LL * skill[j] * mana[i];
            }

            for (int j = n - 2; j >= 0; j--){
                finishTime[j] = finishTime[j + 1] - 1LL * skill[j + 1] * mana[i];
            }
        }

        return finishTime[n - 1];
    }
};