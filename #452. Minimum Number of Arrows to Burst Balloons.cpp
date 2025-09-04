class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<vector<int>>start;
        sort(points.begin(),points.end());
        int count = 1;
        start.push_back(points[0]);
        for(int i =1;i<points.size();i++){
            if(start.back()[1]<points[i][0]){
                count++;
               start.push_back(points[i]);
            }
            else{
            start.back()[1] = min(points[i][1],start.back()[1]);
            }

        }
        return count ;
    }
};