class Solution {
public:
int help(int l,int r,int start,vector<vector<int>>& fruits){
    int left=fruits[l][0];
    int right=fruits[r][0];
    return min(abs(start-left)+(right-left),abs(start-right)+(right-left));
}
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int l=0,r=0,total=0,ans=0;
        int n=fruits.size();
        for(r=0;r<n;r++){
            total+=fruits[r][1];
            while(l<=r&&help(l,r,startPos,fruits)>k){
                total-=fruits[l][1];
                l++;
            }
            ans=max(ans,total);
        }
        return ans;
    }
};