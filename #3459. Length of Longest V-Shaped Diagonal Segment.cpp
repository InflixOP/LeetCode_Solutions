class Solution {
public:
    int dp[501][501][2][4];
    int n,m;

    int solve(int i,int j,bool change,int dir,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i==n || j==m || grid[i][j]==1) return 0; 
        if(dp[i][j][change][dir]!=-1) return dp[i][j][change][dir];
        int ans1 = -1e9 ; int ans2 = -1e9;
        if(dir == 0)
        {
            int prev = grid[i+1][j+1];
            if(prev != 1 && prev == grid[i][j]) return 0;
            ans1 = solve(i-1,j-1,change,dir,grid); // same direction me chal rhe
            if(change == true) ans2 = solve(i-1,j+1,0,1,grid); // take 90 turn
        }
        else if(dir == 1)
        {
            int prev = grid[i+1][j-1];
            if(prev != 1 && prev == grid[i][j]) return 0;
            ans1 = solve(i-1,j+1,change,dir,grid); // same
            if(change == true) ans2 = solve(i+1,j+1,0,2,grid); // turn
        }
        else if(dir == 2)
        {
            int prev = grid[i-1][j-1];
            if(prev != 1 && prev == grid[i][j]) return 0;
            ans1 = solve(i+1,j+1,change,dir,grid); // same
            if(change == true) ans2 = solve(i+1,j-1,0,3,grid); // turn
        }
        else 
        {
            int prev = grid[i-1][j+1];
            if(prev != 1 && prev == grid[i][j]) return 0;
            ans1 = solve(i+1,j-1,change,dir,grid); // same
            if(change == true) ans2 = solve(i-1,j-1,0,0,grid); // turn
        }
        return dp[i][j][change][dir] = 1 + max(ans1,ans2);
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) 
    {
        n = grid.size(); m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    ans = max(ans,1);
                    if(i-1>=0 && j-1>=0 && grid[i-1][j-1] == 2) ans=max(ans,1 + solve(i-1,j-1,1,0,grid));
                    if(i-1>=0 && j+1<m && grid[i-1][j+1] == 2) ans=max(ans,1 + solve(i-1,j+1,1,1,grid));
                    if(i+1<n && j+1<m && grid[i+1][j+1] == 2) ans=max(ans,1 + solve(i+1,j+1,1,2,grid));
                    if(i+1<n && j-1>=0 && grid[i+1][j-1] == 2) ans=max(ans,1 + solve(i+1,j-1,1,3,grid));
                }
            }
        }
        return ans;
    }
};