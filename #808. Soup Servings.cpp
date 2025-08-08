class Solution{
public:
    vector<pair<int,int>>serve={{4,0},{3,1},{2,2},{1,3}};
    vector<vector<double>>dp;
    double solve(int a,int b){
    if(a<=0&&b<=0)
    return 0.5;
    if(a<=0) return 1.0;
    if(b<=0) return 0.0;
    if(dp[a][b]!=-1.0)
    return dp[a][b];
    double prob=0.0;
    for(auto&p:serve){
    prob+=solve(a-p.first,b-p.second);
}
    return dp[a][b]=0.25*prob;
}
    double soupServings(int n){
    if(n>=4800) 
    return 1.0;
    int scaledN=(n+24)/25;
    dp.resize(scaledN+1,vector<double>(scaledN+1,-1.0));
    return solve(scaledN,scaledN);
}
};