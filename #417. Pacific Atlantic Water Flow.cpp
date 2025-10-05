class Solution {
public:
    void dfs(vector<vector<int>>& heights, int row, int col, set<pair<int,int>> &st, vector<vector<int>> &vis){
        if(vis[row][col] == 1){
            return ;
        }
        vis[row][col] = 1;
        st.insert({row, col});
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        for(int i = 0 ; i < 4 ; i++){
            int nrow = row + drow[i];int ncol = col + dcol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < heights.size() && ncol < heights[0].size() && heights[nrow][ncol] >= heights[row][col]){
                dfs(heights, nrow, ncol, st, vis);
            }
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int,int>> pacific;
        set<pair<int,int>> atlantic;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pacificvis(n, vector<int>(m, 0));
        vector<vector<int>> atlanticvis(n, vector<int>(m, 0));

        for(int i = 0 ; i < n ; i++){
            pacific.insert({i, 0});
            atlantic.insert({i, m-1});
            
        }
        for(int j = 0 ; j < m ; j++){
            pacific.insert({0, j});
            atlantic.insert({n-1, j});
            
        }
        for(auto [r,c]: pacific){
            dfs(heights, r, c, pacific, atlanticvis);
        }
        for(auto [r,c]: atlantic){
            dfs(heights, r, c, atlantic, pacificvis);
        }
        vector<vector<int>> ans;
        for(auto [r,c]: pacific){
            if(atlantic.find({r, c}) != atlantic.end())ans.push_back({r, c});
        }
        return ans;
    }
};