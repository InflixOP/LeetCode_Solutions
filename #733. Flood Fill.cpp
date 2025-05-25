class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int curr=image[sr][sc];
            int rv[]={-1,0,1,0};
            int cv[]={0,1,0,-1};
            dfs(sr,sc,curr,image,rv,cv,color);
            return image;
        }
        void dfs(int row,int col,int curr,vector<vector<int>>& image,int rv[] ,int cv[],int color){
            image[row][col]=color;
            int n=image.size();
            int m=image[0].size();
            for(int i=0;i<4;i++){
                int nrow=row+rv[i];
                int ncol=col+cv[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&image[nrow][ncol]==curr&&image[nrow][ncol]!=color)
                dfs(nrow,ncol,curr,image,rv,cv,color);
            }
        }
    };