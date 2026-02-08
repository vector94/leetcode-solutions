class Solution {
    vector<int> graph[100005];
    int cur_time;

void DFS(int u, vector<int>& discovery_time, vector<int>& low, vector<int>& parent, vector<pair<int, int>>& bridge)
{
	discovery_time[u] = low[u] = cur_time;
	cur_time++;

	for(int v : graph[u])
	{
		if(discovery_time[v] == -1)	//If v is not visited
		{
			parent[v] = u;
			DFS(v, discovery_time, low,parent, bridge);
			low[u] = min(low[u], low[v]);

			if(low[v] > discovery_time[u]){
				bridge.push_back({u,v});
			}
		}
		else if(v != parent[u]){	//Ignore child to parent edge
			low[u] = min(low[u], discovery_time[v]);
		}
	}
}

vector<vector<int>> findBridges_Tarjan(int n)
{
	vector<int> discovery_time(n, -1), low(n, -1), parent(n, -1);
	vector<pair<int,int>> bridge;

    cur_time = 0;

	for(int i = 0; i < n; i++){
		if(discovery_time[i] == -1){
			DFS(i, discovery_time, low, parent, bridge);
		}
	}
	
    vector<vector<int> > result;
    
	for(auto it : bridge){
        result.push_back(vector<int>{it.first, it.second});
    }
    
    return result;
}
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        for (int i = 0; i < connections.size(); i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<vector<int> > result;
        
        result = findBridges_Tarjan(n);
        
        return result;
    }
};