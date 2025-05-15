class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>> ans;
            int n=intervals.size();
            vector<int> newi(2,0);
            newi[0]=newInterval[0];
            newi[1]=newInterval[1];
            int i=0;
            while(i<n&&newInterval[0]>intervals[i][1]){
                ans.push_back(intervals[i]);
                i++;
            }
            while(i<n&&intervals[i][0]<=newInterval[1]){
                newi[0]=min(newi[0],intervals[i][0]);
                newi[1]=max(newi[1],intervals[i][1]);
                i++;
            }
            ans.push_back(newi);
            while(i<n&&newInterval[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
               i++;
            }
            return ans;
        }
    };