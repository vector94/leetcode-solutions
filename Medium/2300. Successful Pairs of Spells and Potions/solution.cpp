class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int N = spells.size();

        vector<pair<int, int>> sortedSpells;
        for (int i = 0; i < spells.size(); i++){
            sortedSpells.push_back({spells[i], i});
        }

        sort(sortedSpells.begin(), sortedSpells.end());
        sort(potions.begin(), potions.end());

        vector<int> ans(N);

        int j = potions.size() - 1;
        for (int i = 0; i < sortedSpells.size(); i++){
            int spell = sortedSpells[i].first;
            int idx = sortedSpells[i].second;

            while (j >= 0 && (long long)spell * potions[j] >= success){
                j--;
            }    

            ans[idx] = (potions.size() - j) - 1;
        }

        return ans;
    }
};

/*
    1 3 5
    1 2 3 4 5
*/