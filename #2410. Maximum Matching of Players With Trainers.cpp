class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n=players.size();
        int m=trainers.size();
        int ans=0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        vector<bool> vis(m,false);
        int k=0;
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            int idx=-1;
            for(int j=k;j<m;j++){
                if(!vis[j]){
                    if(trainers[j]>=players[i]&&trainers[j]-players[i]<mini){
                        mini=trainers[j]-players[i];
                        idx=j;
                        k=idx+1;
                        break;
                    }
                }
            }
            if(idx!=-1){
            vis[idx]=true;
            ans++;
            }
        }
        return ans;
    }
};