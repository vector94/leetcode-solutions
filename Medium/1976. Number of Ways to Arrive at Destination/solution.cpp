class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);

        for (int i = 0; i < roads.size(); i++){
            graph[roads[i][0]].push_back(make_pair(roads[i][1], roads[i][2]));
            graph[roads[i][1]].push_back(make_pair(roads[i][0], roads[i][2]));
        }

        vector<long long> dist(n, LONG_LONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> myQueue;
        myQueue.push({0, 0});
        int mod = 1e9 + 7;

        while (!myQueue.empty()){
            int curNode = myQueue.top().second;
            long long curTime = myQueue.top().first;

            myQueue.pop();

            for (int i = 0; i < graph[curNode].size(); i++){
                int nextNode = graph[curNode][i].first;
                long long nextTime = graph[curNode][i].second;

                if (curTime + nextTime < dist[nextNode]){
                    dist[nextNode] = curTime + nextTime;
                    ways[nextNode] = ways[curNode];
                    myQueue.push(make_pair(dist[nextNode], nextNode));
                }
                else if (curTime + nextTime == dist[nextNode]){
                    ways[nextNode] = (ways[nextNode] + ways[curNode]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};