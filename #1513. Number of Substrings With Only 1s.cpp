class Solution {
private:
    const int MOD = 1e9 + 7;

public:
    int numSub(string s) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        s.push_back('0');
        int n = s.size();
        long long cntOnes = 0;
        long long result = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cntOnes++;
                continue;
            }
            result += cntOnes * (cntOnes + 1) / 2;
            result %= MOD;
            cntOnes = 0;
        }
        return result;
    }
};