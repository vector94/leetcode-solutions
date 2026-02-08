class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int N = edges1.size() + 1;
        int M = edges2.size() + 1;

        vector<vector<int>> tree1(N);
        for (int i = 0; i < edges1.size(); i++){
            int u = edges1[i][0];
            int v = edges1[i][1];
            tree1[u].push_back(v);
            tree1[v].push_back(u);
        }

        vector<vector<int>> tree2(M);
        for (int i = 0; i < edges2.size(); i++){
            int u = edges2[i][0];
            int v = edges2[i][1];
            tree2[u].push_back(v);
            tree2[v].push_back(u);
        }

        int secondTarget = getSecondTarget(M, tree2, k);
        vector<int> result;

        for (int i = 0; i < N; i++){
            int cnt = 1 + dfs(-1, i, k, tree1);
            result.push_back(cnt + secondTarget);
        }

        return result;
    }

    int getSecondTarget(int M, vector<vector<int>>& tree, int k){
        if (k == 0) return 0;

        int ret = 0;
        for (int i = 0; i < M; i++){
            int curRet = 1 + dfs(-1, i, k - 1, tree);
            ret = max(ret, curRet);
        }

        return ret;
    }

    int dfs(int parent, int node, int edgeCount, vector<vector<int>>& tree){
        if (edgeCount == 0) return 0;

        int ret = 0;
        for (int nextNode : tree[node]){
            if (nextNode == parent) continue;

            ret += 1 + dfs(node, nextNode, edgeCount - 1, tree);
        }

        return ret;
    }
};