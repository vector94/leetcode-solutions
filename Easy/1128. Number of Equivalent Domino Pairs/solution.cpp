class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> hashMap;

        int N = dominoes.size();
        int ans = 0;

        for (int i = 0; i < N; i++){
            if (dominoes[i][0] > dominoes[i][1]){
                swap(dominoes[i][0], dominoes[i][1]);
            }
            
            ans += hashMap[{dominoes[i][0], dominoes[i][1]}];
            hashMap[{dominoes[i][0], dominoes[i][1]}]++;
        }

        return ans;
    }
};