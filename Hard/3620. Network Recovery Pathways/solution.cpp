class Solution {
public:

    bool check(vector<vector<pair<int, int>>>& graph, int N, long long k, long long maxCost){
        vector<long long> dist(N, LLONG_MAX);
        dist[0] = 0;

        priority_queue <pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()){
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u])    continue;

            for (int i = 0; i < graph[u].size(); i++){
                int v = graph[u][i].first;
                int cost = graph[u][i].second;

                if (cost < maxCost) continue;

                if (d + cost < dist[v]){
                    dist[v] = d + cost;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[N - 1] != LLONG_MAX && dist[N - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int N = online.size();
        vector<vector<pair<int, int>>> graph(N);

        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int cost = edges[i][2];

            if (!online[u] || !online[v])   continue;

            graph[u].push_back({v, cost});
        }
        
        int lo = 0;
        int hi = 1e9;

        int ans = -1;

        while (lo <= hi){
            int mid = (lo + hi) / 2;

            if (check(graph, N, k, mid)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return ans;
    }
};