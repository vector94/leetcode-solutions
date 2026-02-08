class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> graph(c + 1);

        for (int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> groupNo(c + 1, 0);

        int group = 0;

        for (int i = 1; i <= c; i++){
            if (groupNo[i] == 0){
                group++;
                dfs(-1, i, graph, groupNo, group);
            }
        }

        vector<set<int>> groupSet(group + 1);
        vector<bool> gridStatus(c + 1, false);
        for (int i = 1; i <= c; i++){
            groupSet[groupNo[i]].insert(i);
            gridStatus[i] = true;
        }

        vector<int> result;

        for (int i = 0; i < queries.size(); i++){
            int type = queries[i][0];
            int grid = queries[i][1];

            if (type == 1){
                if (gridStatus[grid]){
                    result.push_back(grid);
                }
                else{
                    if (groupSet[groupNo[grid]].size() == 0){
                        result.push_back(-1);
                    }
                    else{
                        result.push_back(*groupSet[groupNo[grid]].begin());
                    }
                }
            }
            else{
                if (gridStatus[grid] == false)  continue;
                gridStatus[grid] = false;
                groupSet[groupNo[grid]].erase(groupSet[groupNo[grid]].find(grid));
            }
        }
        
        return result;
    }

    void dfs(int parent, int curNode, vector<vector<int>>& graph, vector<int>& groupNo, int curGroup){
        if (groupNo[curNode] != 0)  return;
        
        groupNo[curNode] = curGroup;

        for (int nextNode : graph[curNode]){
            if (nextNode == parent) continue;
            dfs(curNode, nextNode, graph, groupNo, curGroup);
        }
    }
};