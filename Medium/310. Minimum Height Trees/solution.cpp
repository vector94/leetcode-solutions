class Solution {
public:
    
    int dfs1(int cur, int parent, vector<vector<int> > &graph, vector<vector<int> > &height){
        for (int next : graph[cur]){
            if (next == parent) continue;
            int curHeight = dfs1(next, cur, graph, height);
            if (curHeight + 1 > height[cur][0]){
                height[cur][1] = height[cur][0];
                height[cur][0] = curHeight + 1;
            }
            else if (curHeight + 1 > height[cur][1]){
                height[cur][1] = curHeight + 1;
            }
        }
        return height[cur][0];
    }
    
    void dfs2(int cur, int parent, vector<vector<int> > &graph, vector<vector<int> > &height){
        if (cur != 0){
            if (height[cur][0] + 1 == height[parent][0]){
                height[cur][1] = max(height[cur][1], height[parent][1] + 1);
            }
            else{
                height[cur][1] = max(height[cur][0], height[parent][1] + 1);
                height[cur][0] = height[parent][0] + 1;
            }
        }
        if (height[cur][0] < height[cur][1]){
            swap(height[cur][0], height[cur][1]);
        }
        for (int next : graph[cur]){
            if (next == parent) continue;
            dfs2(next, cur, graph, height);
        }
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<vector<int> > graph(n);
        for (int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<vector<int> > height(n, vector<int> (2, 0));
        
        dfs1(0, -1, graph, height);
        dfs2(0, -1, graph, height);
        
        
        int minHeight = n;
        for (int i = 0; i < n; i++){
            minHeight = min(minHeight, height[i][0]);
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++){
            if (minHeight == height[i][0]){
                result.push_back(i);
            }
        }
        return result;
    }
};