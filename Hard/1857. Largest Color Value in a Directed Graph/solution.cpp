class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.size();
        vector<vector<int>> graph(N);

        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
        }

        vector<int> visited(N, 0);
        vector<vector<int>> dp(N, vector<int>(26, 0));

        int ans = 0;
        for (int i = 0; i < N; i++){
            if (visited[i] == 0){
                int result = dfs(i, colors, visited, graph, dp);
                if (result == INT_MAX) return -1;
                ans = max(ans, result);
            }
        }

        return ans;
    }

    int dfs(int node, string& colors, vector<int>& visited, vector<vector<int>>& graph, vector<vector<int>>& dp){
        if (visited[node] == 1) {
            return INT_MAX;
        }
        
        if (visited[node] == 2) {
            int maxColorCount = 0;
            for (int c = 0; c < 26; c++) {
                maxColorCount = max(maxColorCount, dp[node][c]);
            }
            return maxColorCount;
        }
        
        visited[node] = 1;
        
        for (int nextNode : graph[node]) {
            if (dfs(nextNode, colors, visited, graph, dp) == INT_MAX) {
                return INT_MAX;
            }
            
            for (int c = 0; c < 26; c++) {
                dp[node][c] = max(dp[node][c], dp[nextNode][c]);
            }
        }
        
        dp[node][colors[node] - 'a']++;
        
        visited[node] = 2; 
        
        int maxColorCount = 0;
        for (int c = 0; c < 26; c++) {
            maxColorCount = max(maxColorCount, dp[node][c]);
        }
        return maxColorCount;
    }
};