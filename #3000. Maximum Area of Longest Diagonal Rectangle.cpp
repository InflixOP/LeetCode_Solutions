class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxi=0;
        int ans=0;
        for(int i=0;i<dimensions.size();i++){
            if(sqrt(pow(dimensions[i][0],2)+pow(dimensions[i][1],2))>maxi){
                maxi=sqrt(pow(dimensions[i][0],2)+pow(dimensions[i][1],2));
                ans=dimensions[i][0]*dimensions[i][1];
            }
             else if(sqrt(pow(dimensions[i][0],2)+pow(dimensions[i][1],2))==maxi){
                ans=max(dimensions[i][0]*dimensions[i][1],ans);
            }
        }
        return ans;
    }
};