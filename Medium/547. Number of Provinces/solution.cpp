class Solution {
public:
    
    void dfs(int cur, vector<vector<int> > &isConnected, vector<bool> &mark){
        mark[cur] = true;
        for (int i = 0; i < isConnected[cur].size(); i++){
            if (isConnected[cur][i] && !mark[i]){
                dfs(i, isConnected, mark);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> mark(n, false);
        
        int result = 0;
        for (int i = 0; i < n; i++){
            if (!mark[i]){
                dfs(i, isConnected, mark);
                result++;
            }
        }
        
        return result;
    }
};