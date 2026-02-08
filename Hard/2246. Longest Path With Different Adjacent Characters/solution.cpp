class Solution {
public:

    int dfs(int curNode, string &s, vector<vector<int> > &graph, int &result) {
        int firstHighest, secondHighest;
        firstHighest = secondHighest = 0;
        for (int nextNode : graph[curNode]){
            int curCount = dfs(nextNode, s, graph, result);
            
            if (s[curNode] != s[nextNode]){
                if (curCount >= firstHighest){
                    secondHighest = firstHighest;
                    firstHighest = curCount;
                }
                else if (curCount > secondHighest){
                    secondHighest = curCount;
                }
            }
        }
        result = max(result, firstHighest + secondHighest + 1);
        return firstHighest + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int> > graph(n);

        for (int i = 0; i < n; i++){
            if (parent[i] == -1)    continue;
            graph[parent[i]].push_back(i);
        }

        int result = 1;
        dfs(0, s, graph, result);

        return result;
    }
};