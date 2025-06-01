class Solution {
    public:
        int n;
    
        pair<int, int> getCoordinates(int num) {
            int rowFromTop = (num - 1) / n;
            int rowFromBottom = (n - 1) - rowFromTop;
            int col = (num - 1) % n;
            if ((n % 2 == 0 && rowFromBottom % 2 == 0) ||
                (n % 2 == 1 && rowFromBottom % 2 == 1)) {
                col = (n - 1) - col;
            }
            return {rowFromBottom, col};
        }
    
        int snakesAndLadders(vector<vector<int>>& board) {
            n = board.size();
            queue<int> q;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            q.push(1);
            vis[n - 1][0] = true;
            int steps = 0;
    
            while (!q.empty()) {
                int size = q.size();
                while (size--) {
                    int x = q.front();
                    q.pop();
                    if (x == n * n)
                        return steps;
    
                    for (int k = 1; k <= 6; k++) {
                        int val = x + k;
                        if (val > n * n)
                            break;
                        auto [r, c] = getCoordinates(val);
                        if (vis[r][c])
                            continue;
                        vis[r][c] = true;
                        if (board[r][c] == -1)
                            q.push(val);
                        else
                            q.push(board[r][c]);
                    }
                }
                steps++;
            }
            return -1;
        }
    };