class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> nodeVisited(n, false);
        map<pair<int, int>, bool> edgeVisited;

        vector<vector<int> > graph(n);
        for (int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++){
            if (!nodeVisited[i]){
                pair<int, int> nodeAndEdge = dfs(i, graph, nodeVisited, edgeVisited);

                int nodeCount = nodeAndEdge.first;
                int edgeCount = nodeAndEdge.second;

                cout << nodeCount << " " << edgeCount << endl;

                if (edgeCount == (nodeCount * (nodeCount - 1)) / 2){
                    ans++;
                }
            }
        }

        return ans;
    }

    pair<int, int> dfs(int curNode, vector<vector<int> >& graph, vector<bool>& nodeVisited, map<pair<int, int>, bool>& edgeVisited){
        nodeVisited[curNode] = true;

        int nodeCount = 1;
        int edgeCount = 0;
        for (int i = 0; i < graph[curNode].size(); i++){
            int nextNode = graph[curNode][i];

            if (!edgeVisited[make_pair(curNode, nextNode)]){
                edgeVisited[make_pair(curNode, nextNode)] = true;
                edgeVisited[make_pair(nextNode, curNode)] = true;
                edgeCount++;
            }
            if (!nodeVisited[nextNode]){
                pair<int, int> curNodeAndEdge = dfs(nextNode, graph, nodeVisited, edgeVisited);

                nodeCount += curNodeAndEdge.first;
                edgeCount += curNodeAndEdge.second;
            }
        }

        return make_pair(nodeCount, edgeCount);
    }

};