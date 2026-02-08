class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int row=board.size();
        int col=board[0].size();
        
        int dx[8]={-1,-1,-1,0,0,1,1,1}; 
        int dy[8]={-1,0,1,-1,1,-1,0,1};
        
       vector<vector<int>>dp(row,vector<int>(col));   
        
        for(int i=0;i<row;i++)                     
        {
            for(int j=0;j<col;j++)
            {
                 int count=0;
                 for(int k=0;k<8;k++)           
                 {
                     int newi=i+dx[k];
                     int newj=j+dy[k];
                     
                     if(newi>=0 && newj>=0 && newi<row && newj<col && board[newi][newj]==1)
                         count++;
                     
                     
                 }
                if(board[i][j]==1 && (count<2 ||count>3)) dp[i][j]=0;        
                else if(board[i][j]==1 && (count ==2 || count==3)) dp[i][j]=1;
                else if(board[i][j]==0 && count==3 ) dp[i][j]=1;
                else dp[i][j]=0;
                 
            }
        }
        board=dp;  
    }
};