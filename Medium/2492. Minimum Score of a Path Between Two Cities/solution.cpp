class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        int ans = INT_MAX;
        vector<bool> mark(n + 1, false);

        queue<int> myQueue;
        myQueue.push(1);
        mark[1] = true;

        while (!myQueue.empty()){
            int u = myQueue.front();
            myQueue.pop();

            for (int i = 0; i < graph[u].size(); i++){
                int v = graph[u][i].first;
                int w = graph[u][i].second;

                ans = min(ans, w);

                if (mark[v])    continue;
                
                mark[v] = true;
                myQueue.push(v);
            }
        }

        return ans;
    }
};