class Solution {
public:
const int MOD = 1e9+7;
typedef long long ll;
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<ll> dp(26);
        for (char c: s) {
            dp[c-'a']++;
        }
        vector<vector<ll>> trans(26, vector<ll>(26));
        for (int i=0; i<26; i++) {
            for (int j=0; j<nums[i]; j++) {
                trans[(i+1+j)%26][i] = 1;
            }
        }
        while (1) {
            if (t & 1) {
                vector<ll> tmp(26);
                for (int i=0; i<26; i++) {
                    for (int j=0; j<26; j++) {
                        tmp[i] = (tmp[i] + (dp[j]*trans[i][j]) % MOD) % MOD;
                    }
                }
                dp = tmp;
            }
            t >>= 1;
            if (t == 0) break;
            vector<vector<ll>> tmp2d(26, vector<ll>(26));
            for (int i=0; i<26; i++) {
                for (int j=0; j<26; j++) {
                    for (int k=0; k<26; k++) {
                        tmp2d[i][j] = (tmp2d[i][j] + (trans[i][k] * trans[k][j]) % MOD) % MOD;
                    }
                }
            }
            trans = tmp2d;
        }
        int ans = 0;
        for (int e: dp) {
            ans = (ans + e) % MOD;
        }
        return ans;
    }
};