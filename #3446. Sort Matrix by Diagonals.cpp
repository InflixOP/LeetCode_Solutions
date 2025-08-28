class Solution {
public:
    void sortDiagonal(int row,int col,vector<vector<int>>&grid,bool asc){
        int n=grid.size();
        vector<int>diag;
        int i=row;
        int j=col;
        while(i<n&&j<n){
            diag.push_back(grid[i][j]);
            i++;
            j++;
        }
        if(asc){
            sort(diag.begin(),diag.end());
        }
        else{
            sort(diag.rbegin(),diag.rend());
        }
        i=row;
        j=col;
        for(auto val:diag){
            grid[i][j]=val;
            i++;
            j++;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int row=0;row<n;row++){
            sortDiagonal(row,0,grid,false);
        }
        for(int col=1;col<n;col++){
            sortDiagonal(0,col,grid,true);
        }
        return grid;
    }
};