class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int n=matrix.size();
            vector<pair<int,int>> mp;
            for(int i=0;i<n;i++){
                for(int j=0;j<matrix[i].size();j++){
                    if(matrix[i][j]==0)
                    mp.push_back({i,j});
                }
            }
            for(int i=0;i<mp.size();i++){
                for(int j=0;j<matrix[0].size();j++){
                    matrix[mp[i].first][j]=0;
                }
                for(int j=0;j<n;j++){
                    matrix[j][mp[i].second]=0;
                }
            }
        }
    };