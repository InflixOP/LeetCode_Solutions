class Solution {

    long long helper(long long limit) {
        int cur = 0;
        long long ans = 0;
        int i = 1;
        while (cur < limit) {
            long long next = ((cur + 1) * 4) - 1;
            next = min(next, limit);
            ans += (next - cur) * 1ll * i;
            i++;
            cur = next;
        }
        return ans;
    }

public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto& query : queries) {
            long long result = (helper(query[1]) - helper(query[0] - 1));
            ans += (result / 2) + (result % 2);
        }
        return ans;
    }
};