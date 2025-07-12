class Solution {
public:
    int rMin=6, rMax=1;
    bool dp[6][28][29]={};
    void f(int round, int l, int r, int n){
        if (dp[round][l][r]) return;
        dp[round][l][r]=1;
        if (l>r) return f(round, r, l, n);
        if (l==r){
            rMin=min(round, rMin);
            rMax=max(round, rMax);
            return ;
        }
        int half=(n+1)/2, iN=min(l, half);
        for(int i=1; i<=iN; i++){
            for(int j=min(half, r)-i; j>=l-i+1; j--)
                if (l+r-(i+j)<=n/2)
                    f(round+1, i, j, half);
        }
    }


    vector<int> earliestAndLatest(int n, int first, int second) {
        f(1, first, n+1-second, n);
        return {rMin, rMax};
        
    }
};