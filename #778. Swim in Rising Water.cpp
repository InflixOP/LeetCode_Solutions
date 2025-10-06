class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>visited(n,vector<int>(n,0));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}}); //time,row,col

        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};

        int time=0;
        while(!pq.empty()){
            int node=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            time=max(time,node);
            if(row==n-1 && col==n-1) return time;
            if(visited[row][col]) continue;
            visited[row][col]=1;

            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n){
                    pq.push({grid[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        return time;
    }
};