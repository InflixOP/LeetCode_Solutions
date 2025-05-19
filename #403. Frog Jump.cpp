class Solution {
    public:
        bool canCross(vector<int>& stones) {
            int n=stones.size();
            vector<unordered_set<int>> dp(n);
            dp[0].insert(0);
            for(int i=1;i<stones.size();i++){
                for(int j=0;j<i;j++){
                    long long gap=(long long)stones[i]-stones[j];
                    if(dp[j].count(gap-1)||dp[j].count(gap)||dp[j].count(gap+1))
                    dp[i].insert(gap);
                }
            }
    return !dp[n-1].empty();
        }
    };