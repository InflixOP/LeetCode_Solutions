static bool comp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) return a[1] <= b[1];
    return a[0] <= b[0];
}
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end(), comp);

        int cnt = meetings[0][0] - 1;
        int last = meetings[0][1];
        for (int i=1; i<n; i++) {
            vector<int> m = meetings[i];
            if (m[0] > last) {
                cnt += m[0]-last-1;
            }
            last = max(last, m[1]);
        }

        int x = days-last;
        if (x > 0) cnt += x;
        return cnt;
    }
};