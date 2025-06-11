class Solution {
public:
void help(int k,int n,int num,vector<int>& v,vector<vector<int>>& ans){
    if(n==0&&k==0){
        ans.push_back(v);
        return;
    }
    if(num>9||n<0||k<0)
    return ;
    help(k,n,num+1,v,ans);
    v.push_back(num);
    help(k-1,n-num,num+1,v,ans);
    v.pop_back();
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        help(k,n,1,v,ans);
        return ans;
    }
};