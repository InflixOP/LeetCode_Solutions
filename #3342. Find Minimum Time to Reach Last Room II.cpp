class Solution {
public:
    typedef pair<pair<int,int>, pair<int,int>> ppi;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        vector<vector<int> > dis (n,vector<int> (m,INT_MAX) );
        dis[0][0]=0;
        pq.push( { {0,2},{0,0} } );
        while(!pq.empty()) {
            int d=pq.top().first.first;
            int t=pq.top().first.second;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            int rd[]={0,1,0,-1};
            int cd[]={-1,0,1,0};
            for(int i=0;i<4;i++) {
                int t2=t;
                if(t2==1) {t2++;}
                else {t2--;}
                int nx=x+rd[i];
                int ny=y+cd[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m)  { 
               int nd=max(d+t2,moveTime[nx][ny]+t2);
                if(dis[nx][ny]>nd) {
                    dis[nx][ny]=nd;
                    pq.push({ {nd,t2},{nx,ny} });
                } 
            }
            }
        }
        return dis[n-1][m-1];
    }
};