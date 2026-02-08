class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int N = edges.size();
        vector<vector<int>> graph(N);

        for (int i = 0; i < edges.size(); i++){
            if (edges[i] == -1) continue;
            graph[i].push_back(edges[i]);
        }

        vector<int> dist1(N, -1), dist2(N, -1);

        bfs(node1, graph, dist1);
        bfs(node2, graph, dist2);

        int minDist = INT_MAX;
        int ans = -1;

        for (int i = 0; i < N; i++){
            if (dist1[i] == -1 || dist2[i] == -1){
                continue;
            }

            int maxDist = max(dist1[i], dist2[i]);
            if (minDist > maxDist){
                minDist = maxDist;
                ans = i;
            }
            else if (minDist == maxDist){
                ans = min(ans, i);
            }
        }

        return ans;
    }

    void bfs(int node, vector<vector<int>>& graph, vector<int>& dist){
        queue<int> myQueue;
        dist[node] = 0;
        myQueue.push(node);

        while (!myQueue.empty()){
            int curNode = myQueue.front();
            myQueue.pop();

            for (int nextNode: graph[curNode]){
                if (dist[nextNode] == -1){
                    dist[nextNode] = 1 + dist[curNode];
                    myQueue.push(nextNode);
                }
            }
        }
    }
};