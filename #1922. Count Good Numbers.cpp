class Solution {
public:
    int MOD = 1e9 + 7;
    int countGoodNumbers(long long n) {
        return (power(5, (n + 1) / 2) % MOD * power(4, n / 2) % MOD) % MOD;
    }

    long long power(long long x, long long n) {
        if (n == 0)
            return 1;
        long long y = power(x, n / 2);
        if (n % 2 == 0) {
            return (y * y) % MOD;
        } else {
            return (x * y * y) % MOD;
        }
    }
};