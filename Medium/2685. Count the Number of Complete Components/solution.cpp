class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> edgeCnt(n, 0);

        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);

            edgeCnt[u]++;
            edgeCnt[v]++;
        }

        vector<int> comp(n, -1);
        int compNo = 0;

        for (int i = 0; i < n; i++){
            if (comp[i] == -1){
                dfs(i, graph, comp, compNo);
                compNo++;
            }
        }

        vector<vector<int>> compList(compNo);
        for (int i = 0; i < n; i++){
            compList[comp[i]].push_back(i);
        }

        int ans = 0;

        for (int i = 0; i < compNo; i++){
            int compSize = compList[i].size();
            bool flag = true;
            for (int node : compList[i]){
                if (edgeCnt[node] < compSize - 1){
                    flag = false;
                    break;
                }
            }

            if (flag)   ans++;
        }

        return ans;
    }

    void dfs(int node, vector<vector<int>>& graph, vector<int>& comp, int compNo){
        comp[node] = compNo;

        for (int v : graph[node]){
            if (comp[v] == -1){
                dfs(v, graph, comp, compNo);
            }
        }
    }
};