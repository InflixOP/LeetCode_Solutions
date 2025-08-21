class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows=mat.size(),cols=mat[0].size(),sum=0,ans=0,minVal;
        vector<vector<int>> preSum(rows,vector<int>(cols,0));
        for(int col=0;col<cols;col++) {
            sum=0;
            for(int row=rows-1;row>=0;row--) {
                if(mat[row][col]==0) {
                    sum=0;
                } else {
                    sum++;
                }
                preSum[row][col]=sum;
            }
        }
        for(int row=0;row<rows;row++) {
            for(int col=0;col<cols;col++) {
                minVal=preSum[row][col];
                for(int index=col;index<cols && preSum[row][index]!=0;index++) {
                    minVal=min(minVal,preSum[row][index]);
                    ans+=minVal;
                }
            }
        }
        return ans;
    }
};