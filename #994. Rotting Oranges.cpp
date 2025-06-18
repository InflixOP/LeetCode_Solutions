class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==2){
                    q.push({{row,col},0});
                    visited[row][col]=2;
                }
            }
        }
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};
        int time=0;
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];

                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]==1&&visited[nrow][ncol]!=2){
                    q.push({{nrow,ncol},t+1});
                    visited[nrow][ncol]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]!=2 && grid[i][j]==1) 
                return -1;
            }
        }
        return time;

    }
};