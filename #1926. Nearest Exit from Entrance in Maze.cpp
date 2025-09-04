class Solution {
public:
int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    bool valid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if ((r != entrance[0] || c != entrance[1]) && (r == 0 || r == n - 1 || c == 0 || c == m - 1)) {
                    return step;
                }
                for (int i = 0; i < 4; i++) {
                    int newr = r + dr[i];
                    int newc = c + dc[i];
                    if (valid(newr, newc, n, m) && maze[newr][newc] == '.') {
                        q.push({newr, newc});
                        maze[newr][newc] = '+'; 
                    }
                }
            }
            step++;
        }
        return -1;
    }
};