#define set_bits __builtin_popcount
class Solution {
public:
    const int mod = 1e9 + 7;
    int bits[31];
    int power[51][31];
    int ncr[31][31];
    int dp[51][31][31][31];
    int magicalSum(int m, int k, vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            power[i][0] = 1;
            for (int j = 1; j < m + 1; j++) {
                power[i][j] = ((long long)a[i] * (power[i][j - 1])) % mod;
            }
        }
        for (int i = 0; i <= 30; i++) {
            ncr[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j])%mod;
            }
        }
        for (int i = 0; i < m + 1; i++)bits[i] = set_bits(i);
        auto reset=[&]()->void{
            for(int i=0;i<n;i++){
                for(int j=0;j<=m;j++){
                    for(int kk=0;kk<=m;kk++){
                        for(int mm=0;mm<=k;mm++){
                            dp[i][j][kk][mm]=-1;
                        }
                    }
                }
            }
        };
        reset();
        auto func = [&](int ind, int carry, int sz, int cnt,auto&& func) -> int {
            if (ind == n) {
                if (sz != m || cnt + bits[carry] != k)return 0;
                return 1;
            }
            if (cnt>k)return 0;
            if(dp[ind][carry][sz][cnt]!=-1)return dp[ind][carry][sz][cnt];
            int ans = 0;
            for (int i = 0; i <= m - sz; i++) {
                int mul = power[ind][i];
                int newcarry = carry + i;
                int x = newcarry & 1;
                mul = ((long long)mul*func(ind + 1, newcarry / 2, sz + i, cnt + x, func))%mod;
                mul = ((long long)mul*ncr[m-sz][i])%mod;
                ans = (ans + mul) % mod;
            }
            return dp[ind][carry][sz][cnt]=ans;
        };
        return func(0, 0, 0, 0, func);
    }
};