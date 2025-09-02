class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const auto& a,const auto& b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        int n=points.size(), result=0;
        for(int i=0;i<n;i++){
            int top=points[i][1];
            int bot=INT_MIN;
            for(int j=i+1;j<n;j++){
                int y=points[j][1];
                if(bot<y&&y<=top){
                    result++;
                    bot=y;
                    if(bot==top) break;
                }
            }
        }
        return result;

    }
};