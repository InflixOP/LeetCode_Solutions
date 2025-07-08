class Solution {
public:
    int solve(vector<vector<int>>& events, int ind, int n, int k, int t, vector<vector<int>> &dp){
        if(ind == n || k == 0) return 0;
        if(dp[ind][k] != -1) return dp[ind][k];
        int take = 0;
        if(events[ind][0] > t){ // Find the next possible index to take
            int ind_ = ind+1;
            while(ind_ < n && events[ind_][0] <= events[ind][1]) ind_++;
            take = events[ind][2] + solve(events, ind_, n, k-1, events[ind][1],dp);
        }
        int notTake = solve(events, ind+1, n, k, t, dp);
        return dp[ind][k] = max(take, notTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return solve(events,0,n,k,0,dp);
    }
};