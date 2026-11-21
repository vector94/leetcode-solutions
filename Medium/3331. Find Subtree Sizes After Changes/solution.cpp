class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int N = s.size();
        vector<vector<int>> graph(N);

        for (int i = 1; i < N; i++){
            graph[parent[i]].push_back(i);
        }

        vector<int> lastAncestor(N, -1);
        vector<int> charNodes(26, -1);
        getLastAncestor(-1, 0, graph, s, lastAncestor, charNodes);
        
        for (int i = 0; i < N; i++){
            graph[i].clear();
        }
        for (int i = 1; i < N; i++){
            int p = parent[i];
            if (lastAncestor[i] != -1 && lastAncestor[i] != p){
                p = lastAncestor[i];
            }

            graph[p].push_back(i);
        }

        vector<int> result(N, 0);
        countSubtree(0, graph, result);

        return result;
    }

    void getLastAncestor(
        int parent, 
        int curNode, 
        vector<vector<int>> &graph, 
        string &s,
        vector<int> &lastAncestor,
        vector<int> charNodes
    ){
        int charIdx = s[curNode] - 'a';
        if (charNodes[charIdx] != -1){
            lastAncestor[curNode] = charNodes[charIdx];
        }

        charNodes[charIdx] = curNode;
        for (int nextNode : graph[curNode]){
            getLastAncestor(curNode, nextNode, graph, s, lastAncestor, charNodes);
        }
    }

    int countSubtree(int node, vector<vector<int>> &graph, vector<int> &result){
        int total = 1;
        for (int nextNode : graph[node]){
            total += countSubtree(nextNode, graph, result);
        }

        result[node] = total;
        return total;
    }
};