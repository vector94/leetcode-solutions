class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);

        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        pair<long long, int> ret = dfs(-1, 0, graph, values, k);
        if (ret.first != 0) return ret.second + 1;
        return ret.second;
    }

    pair<long long, int> dfs(int parent, int curNode, vector<vector<int>>& graph, vector<int>& values, int k){
        pair<long long, int> curRet;

        long long curSum = values[curNode];
        int curCnt = 0;
        for (int nextNode : graph[curNode]){
            if (nextNode == parent) continue;
            pair<int, int> ret = dfs(curNode, nextNode, graph, values, k);
            curSum += ret.first;
            curCnt += ret.second;
        }

        if (curSum % k == 0){
            curSum = 0;
            curCnt++;
        }

        curRet = {curSum, curCnt};
        return curRet;
    }
};