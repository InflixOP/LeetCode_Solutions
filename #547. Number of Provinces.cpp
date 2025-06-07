class Solution {
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            int ans=0;
            int n=isConnected.size();
            vector<int> vis(n,0);
            for(int i=0;i<n;i++){
                if(vis[i]==0){
                    ans++;
                    dfs(i,isConnected,vis);
                }
            }
            return ans;
        }
        void dfs(int node,vector<vector<int>>& isConnected,vector<int>& vis){
            vis[node]=1;
            for(int i=0;i<isConnected.size();i++){
                if(isConnected[node][i]&&!vis[i])
                dfs(i,isConnected,vis);
            }
        }
    };