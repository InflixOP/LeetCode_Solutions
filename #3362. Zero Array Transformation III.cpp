class Solution {
    public:
        int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
            int n=nums.size();
            sort(queries.begin(),queries.end());
            priority_queue<int> pq;
            priority_queue<int,vector<int>,greater<int>> req;
            int c=0;
            int j=0;
            for(int i=0;i<n;i++){
                while(j<queries.size()&&queries[j][0]==i){
                    pq.push(queries[j][1]);
                    j++;
                }
                nums[i]-=req.size();
                while(nums[i]>0&&!pq.empty()&&pq.top()>=i){
                    c++;
                    req.push(pq.top());
                    pq.pop();
                    nums[i]--;
                }
                if(nums[i]>0) return -1;
                while(!req.empty()&&req.top()==i) req.pop();
            }
            return queries.size()-c;
        }
    };