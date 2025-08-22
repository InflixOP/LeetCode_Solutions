class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int l1=INT_MAX,r1=INT_MIN,l2=INT_MAX,r2=INT_MIN;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    l1=min(l1,j);
                    r1=max(r1,j);
                    l2=min(l2,i);
                    r2=max(r2,i);
                }
            }
        }
        return (r1-l1+1)*(r2-l2+1);
    }
};