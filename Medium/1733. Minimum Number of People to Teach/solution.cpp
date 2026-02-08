class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sadUsers;

        for (int i = 0; i < friendships.size(); i++){
            bool flag = false;

            int u = friendships[i][0];
            int v = friendships[i][1];

            for (int l1 : languages[u - 1]){
                for (int l2 : languages[v - 1]){
                    if (l1 == l2){
                        flag = true;
                        break;
                    }
                }
            }

            if (!flag){
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }

        vector<int>languageCount(n + 1, 0);
        int mostLanguageCnt = 0;

        for (int user : sadUsers){
            for (int i = 0; i < languages[user - 1].size(); i++){
                languageCount[languages[user - 1][i]]++;
                mostLanguageCnt = max(mostLanguageCnt, languageCount[languages[user - 1][i]]);
            }
        }

        return sadUsers.size() - mostLanguageCnt;
    }
};