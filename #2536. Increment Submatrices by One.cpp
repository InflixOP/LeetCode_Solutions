class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n, 0));
        for(vector<int> &query : queries) {
            int row1 = query[0];
            int col1 = query[1];

            int row2 = query[2];
            int col2 = query[3];

            for(int i = row1; i <= row2; i++) {
                diff[i][col1] += 1;

                if(col2+1 < n) {
                    diff[i][col2+1] -= 1;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                diff[i][j] += diff[i][j-1];
            }
        }

        return diff;
    }
};