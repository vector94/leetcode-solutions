class Solution {
public:
    
    void allPathHelper(int curr, int dest, vector<vector<int>>& graph, vector<int> &path, 
                       vector<int>& visited, vector<vector<int>>& result){
        if (visited[curr]){
            return;
        }
        if (curr == dest){
            path.push_back(curr);
            result.push_back(path);
            path.pop_back();
            return;
        }
        
        visited[curr] = true;
        path.push_back(curr);
        
        for (auto next : graph[curr]){
            allPathHelper(next, dest, graph, path, visited, result);
        } 
        
        visited[curr] = false;
        path.pop_back();
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, false);
        vector<vector<int> > result;
        vector<int> path;
        allPathHelper(0, n - 1, graph, path, visited, result);
        
        return result;
    }
};