class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int n=cost.size();
            vector<int> dp(n,0);
            dp[0]=cost[0];
            dp[1]=cost[1];
            for(int i=2;i<n;i++){
                int l=dp[i-1]+cost[i];
                int r=dp[i-2]+cost[i];
                dp[i]=min(l,r);
            }
            return min(dp[n-1],dp[n-2]);
        }
    };