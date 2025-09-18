class TaskManager {
public:
    unordered_map<int,pair<int,int>> mpp ;
    priority_queue<pair<int,int>>pq ;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &it:tasks)
        {
            pq.push({it[2],it[1]});
            mpp[it[1]]={it[0],it[2]};
        }
    }
    void add(int userId, int taskId, int priority) {
        pq.push({priority,taskId});
        mpp[taskId]={userId,priority} ;
    }
    void edit(int taskId, int newPriority) {
        pq.push({newPriority,taskId}) ;
        mpp[taskId].second=newPriority ;
    }
    void rmv(int taskId) {
        mpp.erase(taskId) ;
    }
    int execTop() {
        while(!pq.empty())
        {
            int t=pq.top().second ;
            int p=pq.top().first ;
            if(mpp.find(t)!=mpp.end()&&mpp[t].second==p) 
            {
                int id=mpp[t].first ;
                mpp.erase(t) ;
                pq.pop() ;
                return id ;
            }
            else pq.pop() ;
        }
        return -1 ;
    }
};
 