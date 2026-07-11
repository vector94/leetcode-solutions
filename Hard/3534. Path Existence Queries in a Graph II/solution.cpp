class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> myNums;

        for (int i = 0; i < n; i++){
            myNums.push_back({nums[i], i});
        }

        sort(myNums.begin(), myNums.end());
        vector<int> idx(n);

        for (int i = 0; i < n; i++){
            idx[myNums[i].second] = i;
        }

        int col = log2(n) + 1;
        vector<vector<int>> ancestorTable(n, vector<int>(col));

        int r = 0;
        for (int l = 0; l < n; l++){
            if (r < l) r = l;

            while (r + 1 < n && myNums[r + 1].first - myNums[l].first <= maxDiff){
                r++;
            }

            ancestorTable[l][0] = r;
        }

        for (int j = 1; j < col; j++){
            for (int i = 0; i < n; i++){
                ancestorTable[i][j] = ancestorTable[ancestorTable[i][j - 1]][j - 1];
            }
        }

        vector<int> result;
        for (int i = 0; i < queries.size(); i++){
            int u = queries[i][0];
            int v = queries[i][1];

            int a = idx[u];
            int b = idx[v];

            if (a == b){
                result.push_back(0);
                continue;
            }

            if (a > b)  swap(a, b);

            int cur = a;
            int jumps = 0;

            for (int j = col - 1; j >= 0; j--){
                if (ancestorTable[cur][j] < b){
                    cur = ancestorTable[cur][j];
                    jumps += (1 << j);
                }
            }

            if (ancestorTable[cur][0] >= b){
                result.push_back(jumps + 1);
            }
            else{
                result.push_back(-1);
            }
        }

        return result;
    }
};