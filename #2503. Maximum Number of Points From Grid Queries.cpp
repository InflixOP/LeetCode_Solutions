class Solution 
{
public:
    int n, m, k;
    int r[4] = {-1, 0, 1, 0};
    int c[4] = {0, 1, 0, -1};
    using p = pair<int, pair<int, int>>;
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) 
    {
        n = grid.size();
        m = grid[0].size();
        k = queries.size();
        vector<int> ans(k);
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < k; i++) 
        {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int points = 0;
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1; 
        for (auto &[queryVal, queryInd] : sortedQueries) 
        {
            while (!pq.empty() && pq.top().first < queryVal) 
            {
                p topElement = pq.top();
                pq.pop();
                int i = topElement.second.first, j = topElement.second.second;
                points++;
                for (int dir = 0; dir < 4; dir++) 
                {
                    int nR = i + r[dir], nC = j + c[dir];
                    if (nR >= 0 && nR < n && nC >= 0 && nC < m && !vis[nR][nC]) 
                    {
                        vis[nR][nC] = 1;
                        pq.push({grid[nR][nC], {nR, nC}});
                    }
                }
            }
            ans[queryInd] = points;
        }
        return ans;
    }
};