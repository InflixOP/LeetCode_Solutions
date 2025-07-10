class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> gap(n+1);
        gap[0]=startTime[0];
        gap[n]=eventTime-endTime[n-1];
        for(int i=1;i<n;i++){
            gap[i]=startTime[i]-endTime[i-1];
        }
        cout<<gap[n-1];
       int maxi=0;
      vector<int> maxl(n+1,0);
      vector<int> maxr(n+1,0);
      for(int i=n-1;i>=0;i--){
        maxr[i]=max(maxr[i+1],gap[i+1]);
      }
      for(int i=1;i<n+1;i++){
        maxl[i]=max(maxl[i-1],gap[i-1]);
      }
      for(int i=1;i<n+1;i++){
        int d=endTime[i-1]-startTime[i-1];
        if(d<=max(maxr[i],maxl[i-1]))
        maxi=max(maxi,d+gap[i]+gap[i-1]);
        maxi=max(maxi,gap[i]+gap[i-1]);
      }
       return maxi;
    }
};