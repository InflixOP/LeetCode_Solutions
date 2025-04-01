class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int n=questions.size();
            vector<long long> dp(n+1,0);
            for(int i=n-1;i>=0;i--){
                int p=questions[i][0];
                int b=questions[i][1];
                int ni=min(n,i+b+1);
                long long solve=p+dp[ni];
                long long skip=dp[i+1];
                dp[i]=max(solve,skip);
            }
            return dp[0];
        }
    };