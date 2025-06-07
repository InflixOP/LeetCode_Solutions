class Solution {
    public:
    static bool cmp(vector<int> a,vector<int> b){
            return b[1]>a[1];
        }
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            int c=1;
            sort(intervals.begin(),intervals.end(),cmp);
            int last=intervals[0][1];
            for(int i=1;i<intervals.size();i++){
                if(intervals[i][0]>=last){
                    c++;
                    last=intervals[i][1];
                }
            }
            return intervals.size()-c;
        }
    };