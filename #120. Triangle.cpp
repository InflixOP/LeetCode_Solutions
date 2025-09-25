const int N=202;
class Solution {
public:

    long long dp[N][N];
    bool vis[N][N];
    long long solve(int i,int j,vector<vector<int>>& arr,int n){
        if(j>=n) return INT_MAX;
        if(i==n) return 0;
        if(vis[i][j]) return dp[i][j];
        vis[i][j]=1;
        long long ans=arr[i][j]+min(solve(i+1,j,arr,n) , solve(i+1,j+1,arr,n));
        return dp[i][j]=ans;
    }

    int minimumTotal(vector<vector<int>>& arr) {
        int n=arr.size();
        memset(dp,-1,sizeof dp);
        return solve(0,0,arr,n);
    }
};