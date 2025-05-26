class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int n=mat.size();
            int m=mat[0].size();
            vector<vector<int>> ans(n,vector<int> (m,89423324));
            queue<pair<int,int>> q;
           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)
                ans[i][j]=0;
                q.push({i,j});
            }
           }
           int rv[]={-1,0,1,0};
            int cv[]={0,1,0,-1};
           while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
             for(int i=0;i<4;i++){
                int nrow=rv[i]+r;
                int ccol=cv[i]+c;
                if(nrow>=0&&nrow<n&&ccol>=0&&ccol<m){
                    if(ans[nrow][ccol]>ans[r][c]+1){
                        ans[nrow][ccol]=ans[r][c]+1;
                        q.push({nrow,ccol});                }
             }
           }
        }
        return ans;
        }
    };