class Solution {
public:
    vector<int> dfs(int curNode, int parentNode, vector<vector<int> > &graph, string &labels, vector<vector<int> > &labelCount){
        vector<int> ret (26, 0);
        ret[labels[curNode] - 'a']++;
        for (int nextNode: graph[curNode]){
            if (nextNode == parentNode) continue;
            vector<int> cur = dfs(nextNode, curNode, graph, labels, labelCount);
            for (int i = 0; i < 26; i++){
                ret[i] += cur[i];
            }
        }
        labelCount[curNode][labels[curNode] - 'a'] = ret[labels[curNode] - 'a'];
        return ret;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> labelCount(n, vector<int>(26, 0));
        vector<vector<int> > graph(n);

        for (auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        dfs(0, -1, graph, labels, labelCount);
        vector<int> result;

        for (int i = 0; i < n; i++){
            result.push_back(labelCount[i][labels[i] - 'a']);
        }

        return result;
    }
};