class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // time, {x, y}
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n - 1 && y == m - 1) return time;

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && moveTime[nx][ny] != -1) {
                    int tt = time;
                    if(time < moveTime[nx][ny]) tt += (moveTime[nx][ny] - time);
                    pq.push({tt + 1, {nx, ny}});
                    moveTime[nx][ny] = -1;
                }
            }
        }
        return -1;
    }
};