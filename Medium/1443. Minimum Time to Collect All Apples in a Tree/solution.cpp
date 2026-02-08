class Solution {
public:

    int minTimeHelper(int curNode, int parentNode, vector<vector<int>>& graph, vector<bool>& hasApple){
        int totalTime = 0;

        for (int nextNode: graph[curNode]){
            if (nextNode == parentNode) continue;
            int childTime = minTimeHelper(nextNode, curNode, graph, hasApple);

            cout << curNode << " " << nextNode << " " << childTime << endl;

            if (hasApple[nextNode] || childTime != 0){
                totalTime += childTime + 2;
            }
        }

        return totalTime;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int> > graph(n);
        for (auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int result = minTimeHelper(0, -1, graph, hasApple);

        return result;
    }
};