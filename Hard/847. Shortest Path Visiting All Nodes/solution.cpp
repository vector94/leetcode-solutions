class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        map<pair<int, int>, bool> visited;
        queue<pair<int, pair<int, int>> > myQueue;
        for (int i = 0; i < n; i++){
            int mask = (1 << i);
            myQueue.push({i, {mask, 0}});
            visited[{i, mask}] = true; 
        }
        
        while (!myQueue.empty()){
            int curNode = myQueue.front().first;
            int curMask = myQueue.front().second.first;
            int dist = myQueue.front().second.second;
            myQueue.pop();
            
            if (curMask == (1 << n) - 1){
                return dist;
            }
            
            for (int nextNode : graph[curNode]){
                int nextMask = curMask | (1 << nextNode);
                if (visited[{nextNode, nextMask}])  continue;
                myQueue.push({nextNode, {nextMask, dist + 1}});
                visited[{nextNode, nextMask}] = true;
            }
        }
        return 0;
    }
};