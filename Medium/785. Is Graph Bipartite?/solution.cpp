class Solution {
public:
    int color[105];
    
    bool solve(vector<vector<int>> &graph, int cur){
        queue<int> Q;
        color[cur] = 1;
        Q.push(cur);
        while (!Q.empty()){
            int x = Q.front();
            Q.pop();
            for (auto y : graph[x]){
                if (color[y] != 0){
                    if (color[x] == color[y]){
                        return false;
                    }
                    continue;
                }
                if (color[x] == 1){
                    color[y] = 2;
                }
                else{
                    color[y] = 1;
                }
                Q.push(y);
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        bool ret = true;
        for (int i = 0; i < graph.size(); i++){
            if (color[i] == 0){
                ret &= solve(graph, i);
            }
        }
        return ret;
    }
};