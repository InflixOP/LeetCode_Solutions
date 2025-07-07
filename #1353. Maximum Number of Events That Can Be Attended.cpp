class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
     int ans=0;
     int maxi=0;
        int n=events.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,events[i][1]);
        }
        priority_queue<int,vector<int>,greater<>> pq;
        sort(events.begin(),events.end());
        int j=0;
        for(int i=1;i<=maxi;i++){
            while(j<n&&events[j][0]<=i){
                pq.push(events[j][1]);
                j++;
            }
            while(!pq.empty()&&pq.top()<i)
            pq.pop();
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};