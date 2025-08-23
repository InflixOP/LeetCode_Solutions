class Solution {
    int minarea(vector<vector<int>>& grid,int top,int bottom,int left,int right){
            if (top > bottom || left > right) return 0;
            int rs=INT_MAX,re=INT_MIN,cs=INT_MAX,ce=INT_MIN;
            for(int i=top;i<=bottom;i++){
                for(int j=left;j<=right;j++){
                    if(grid[i][j]==1){
                        rs=min(rs,i);
                        re=max(re,i);
                        cs=min(cs,j);
                        ce=max(ce,j);
                    }
                }
            }
            if(rs==INT_MAX) return 0;
            return (re-rs+1)*(ce-cs+1);
        }
public:
    int minimumSum(vector<vector<int>>& grid) {
    int mini=INT_MAX;
    int m=grid.size();
    int n=grid[0].size();
    for (int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            int a1=minarea(grid,0,i,0,n-1);
            int a2=minarea(grid,i+1,j,0,n-1);
            int a3=minarea(grid,j+1,m-1,0,n-1);
            if(a1>0 && a2>0 && a3>0) mini=min(mini,(a1+a2+a3));
        }
    }
    for (int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int a1=minarea(grid,0,m-1,0,i);
            int a2=minarea(grid,0,m-1,i+1,j);
            int a3=minarea(grid,0,m-1,j+1,n-1);
            if(a1>0 && a2>0 && a3>0) mini=min(mini,(a1+a2+a3));
        }
    }
    for (int i=0;i<m-1;i++){
        for(int j=0;j<n-1;j++){
            int a1=minarea(grid,0,i,0,j);
            int a2=minarea(grid,0,i,j+1,n-1);
            int a3=minarea(grid,i+1,m-1,0,n-1);
            if(a1>0 && a2>0 && a3>0) mini=min(mini,(a1+a2+a3));
            a1=minarea(grid,0,i,0,n-1);
            a2=minarea(grid,i+1,m-1,0,j);
            a3=minarea(grid,i+1,m-1,j+1,n-1);
            if(a1>0 && a2>0 && a3>0) mini=min(mini,(a1+a2+a3));
        }
    }
    for (int j=0;j<n-1;j++){
        for(int i=0;i<m-1;i++){
            int a1=minarea(grid,0,i,0,j);
            int a2=minarea(grid,i+1,m-1,0,j);
            int a3=minarea(grid,0,m-1,j+1,n-1);
            if(a1>0 && a2>0 && a3>0) mini=min(mini,(a1+a2+a3));
            a1=minarea(grid,0,m-1,0,j);
            a2=minarea(grid,0,i,j+1,n-1);
            a3=minarea(grid,i+1,m-1,j+1,n-1);
            if(a1>0 && a2>0 && a3>0) mini=min(mini,(a1+a2+a3));
        }
    }
    return mini;
    }
};