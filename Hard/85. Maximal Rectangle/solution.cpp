class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mt) {
        int m = mt.size();
        if (m == 0) return 0;
        int n = mt[0].size();
        
        
        vector<vector<int> > matrix(m, vector<int> (n));
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i == 0){
                    matrix[i][j] = mt[i][j] - '0';
                }
                else{
                    if (mt[i][j] != '0'){
                        matrix[i][j] = (mt[i][j] - '0') + matrix[i - 1][j];
                    }
                    else{
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        
        int result = 0;
        
        for (int i = 0; i < m; i++){
            
            int curArea = 0;
            stack<pair<int, int>> ST;
            
            for (int j = 0; j < n; j++){
                
                if (ST.empty() || ST.top().first < matrix[i][j]){
                    ST.push({matrix[i][j], j});
                }
                
                else{
                    int maxLeft = j;
                    
                    while (!ST.empty() && ST.top().first >= matrix[i][j]){
                        int curHeight = ST.top().first;
                        int curLeft = ST.top().second;
                        
                        ST.pop();
                        
                        curArea = max(curArea, curHeight * (j - curLeft));
                        maxLeft = min(maxLeft, curLeft);
                    }
                    
                    ST.push({matrix[i][j], maxLeft});
                }
            }
            
            while (!ST.empty()){
                int curHeight = ST.top().first;
                int width = n - ST.top().second;
                ST.pop();
                curArea = max(curArea, curHeight * width);
            }
            //cout << i << " " << curArea << endl;
            result = max(result, curArea);
        }
        
        return result;
    }
};