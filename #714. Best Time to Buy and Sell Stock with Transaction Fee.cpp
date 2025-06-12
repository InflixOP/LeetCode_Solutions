class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<long> ah(2,0);
        vector<long> curr(2,0);
        ah[0]=ah[1]=0;
        long pro;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==0)
                pro=max(ah[0],-prices[i]+ah[1]);
                if(j==1)
                pro=max(ah[1],prices[i]-fee+ah[0]);
                curr[j]=pro;
            }
            ah=curr;
        }
        return curr[0];
    }
};