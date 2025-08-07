class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[0][n-1]=fruits[0][n-1];
        dp[n-1][0]=fruits[n-1][0];
        int j=n-1;
        int sum=0;
        sum+=fruits[0][0];
        for(int i=1;i<n;i++){
            sum+=fruits[i][i];
            if(j-1>i)j--;
            else if(j-1<i)j++;
            for(int k=j;k<n;k++){
                if(k<n-1){dp[i][k] = fruits[i][k]+max(dp[i-1][k],max(dp[i-1][k-1],dp[i-1][k+1]));
                    dp[k][i]= fruits[k][i]+max(dp[k][i-1],max(dp[k-1][i-1],dp[k+1][i-1]));
                }
                else {dp[i][k]=fruits[i][k]+max(dp[i-1][k],dp[i-1][k-1]);
                    dp[k][i]=fruits[k][i]+max(dp[k][i-1],dp[k-1][i-1]);
                }
            }
        }
        sum+=dp[n-1][n-2];
        sum+=dp[n-2][n-1];
        return sum; 
        
    }
};