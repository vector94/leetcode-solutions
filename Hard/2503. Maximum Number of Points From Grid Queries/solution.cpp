class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < k; i++){
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result(k, 0);
        
        map<pair<int, int>, bool> inHeap;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        vector<int> dx({1, 0, -1, 0}), dy({0, 1, 0, -1});
        
        int queryIndex = 0;
        
        minHeap.push({grid[0][0], {0, 0}});
        int nodeVisited = 0;
        inHeap[{0, 0}] = true;

        while (!minHeap.empty() && queryIndex < k){
            int y = minHeap.top().second.first;
            int x = minHeap.top().second.second;
            
            minHeap.pop();

            while (queryIndex < k && grid[y][x] >= sortedQueries[queryIndex].first){
                queryIndex++;
            }

            nodeVisited++;
            for (int i = queryIndex; i < k; i++){
                result[sortedQueries[i].second] = nodeVisited;
            }

            for (int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny >= 0 && ny < grid.size() && nx >= 0 && nx < grid[0].size() && !inHeap[{ny, nx}]){
                    minHeap.push({grid[ny][nx], {ny, nx}});
                    inHeap[{ny, nx}] = true;
                }
            }
        }

        return result;
    }
};