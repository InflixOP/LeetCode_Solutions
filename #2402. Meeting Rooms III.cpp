class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n,0);
        sort(meetings.begin(),meetings.end());
        priority_queue<int,vector<int> ,greater<int>> avail;
        for(int i=0;i<n;i++){
            avail.push(i);
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
        for(auto ele:meetings){
            int start=ele[0];
            int end=ele[1];
            while(!pq.empty()&&pq.top().first<=start){
                int room=pq.top().second;
                pq.pop();
                avail.push(room);
            }
            if(!avail.empty()){
                int room=avail.top();
                avail.pop();
                pq.push({end,room});
                rooms[room]++;
            }else{
                auto [e,room]=pq.top();
                pq.pop();
                long long s=e+end-start;
                pq.push({s,room});
                rooms[room]++;
            }
        }
        int maxi=0;
        for(int i=1;i<n;i++){
            if(rooms[i]>rooms[maxi])
            maxi=i;
        }
        return maxi;
    }
};