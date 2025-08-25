class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int i=0,j=0;
        int n=mat.size();
        int m=mat[0].size();
        while(ans.size()<n*m){
            while(i>=0&&j<m){
                ans.push_back(mat[i][j]);
                i--;
                j++;
            }
            if(j>=m){
                j--;
                i+=2;
            }
            else
            i++;
              while(i<n&&j>=0){
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
            if(i>=n){
                i--;
                j+=2;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};