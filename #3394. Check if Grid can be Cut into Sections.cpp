class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        int n=intervals.size();
        vector<vector<int>> result;
        sort(begin(intervals),end(intervals));
        result.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]<result.back()[1]){
                result.back()[1]=max(result.back()[1],intervals[i][1]);
            }else
            result.push_back(intervals[i]);
        }
        return result;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> hor;
        vector<vector<int>> ver;
        for(auto &c:rectangles){
            int x1=c[0];
            int y1=c[1];
            int x2=c[2];
            int y2=c[3];
            hor.push_back({x1,x2});
            ver.push_back({y1,y2});
        }
        vector<vector<int>> r1=merge(hor);
        vector<vector<int>> r2=merge(ver);
        return r1.size()>=3||r2.size()>=3;
    }
};