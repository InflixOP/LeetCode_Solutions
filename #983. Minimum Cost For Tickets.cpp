class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
    unordered_map<int,int>map;
     int n=days.size();
     for(int i=0;i<n;i++){
        map[days[i]]++;
     }
     int sum=days[n-1];
     vector<int>dp(sum+1,1e9);
     dp[0]=0;
     for(int i=1;i<=sum;i++){
        if(map.find(i)!=map.end()){
                int u=max(0,i-30);
                  dp[i]=min(dp[i],dp[u]+cost[2]);
                int u1=max(0,i-7);
                  dp[i]=min( dp[i],dp[u1]+cost[1]);
            dp[i]=min( dp[i],dp[i-1]+cost[0]);}
            else{
                dp[i]=min(dp[i],dp[i-1]);
            }
         }  
       return dp[sum];
    }
};