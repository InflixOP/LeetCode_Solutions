class Solution {
public:
    int MOD = 1e9 + 7;
    const static int bound = 1e5;
    long long fact[bound];
    long long inv_fact[bound];

    int countGoodArrays(int n, int m, int k) {
        preprocessing();
        return binomCoef(n - 1, k) * m % MOD * binaryPow(m - 1, n - k - 1) % MOD;
    }

    long long binaryPow(long long x, int n) {
        long long output = 1;
        while (n) {
            if (n & 1) output = output * x % MOD;
            x = x * x % MOD;
            n >>= 1;
        }
        return output;
    }

    long long binomCoef(int n, int m) {
        return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
    }

    void preprocessing() {
        if (fact[0]) return;
        fact[0] = 1;
        for (int i = 1; i < bound; ++i) fact[i] = fact[i - 1] * i % MOD;
        inv_fact[bound - 1] = binaryPow(fact[bound - 1], MOD - 2);
        for (int i = bound - 1; i; --i) inv_fact[i - 1] = inv_fact[i] * i % MOD;
    }
};