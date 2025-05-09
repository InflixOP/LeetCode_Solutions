#define ll long long

class Solution {
public:
    vector<ll> fact, invfact, invnum;
    ll p = 1e9+7, ways, n, len;
    
    Solution() {
        fact.resize(81); // Factorials up to 80
        invfact.resize(81); // Inverse factorials up to 80
        invnum.resize(81); // Modular inverses up to 80
        
        // Initialize factorial and inverse arrays
        fact[0] = fact[1] = 1;
        invfact[0] = invfact[1] = 1;
        invnum[0] = invnum[1] = 1;

        // Compute factorials and modular inverses up to 80 using MOD p
        for (ll i = 2; i <= 80; i++) {
            fact[i] = (i * fact[i-1]) % p;
            invnum[i] = (invnum[p % i] * (p - p / i)) % p;
            invfact[i] = (invnum[i] * invfact[i-1]) % p;
        }
    }

    ll dp[10][41][361]; // DP array for memoization (10 digits, up to 40 selected digits, sum up to 360)

    // Recursive utility function with memoization
    ll util(vector<ll> &fq, ll i, ll sum, ll m) {
        // Base case: Check if sum and digit count requirements are met
        if(i > 9) {
            if (!m && !sum) return ways; // Balanced permutation found
            return 0; // No valid solution in this branch
        }

        // If remaining digits/length exceeds targets, return 0
        if(m < 0 || sum < 0) return 0;

        // Return memoized result if available
        if (dp[i][m][sum] != -1) return dp[i][m][sum];

        ll ans = 0; // Store total balanced permutations in this branch

        // Explore different counts for the current digit `i`
        for (ll j = 0; j <= fq[i]; j++) {
            ll a = util(fq, i + 1, sum - j * i, m - j); // Recursive call

            // Adjust result with factorial inversions to account for duplicate counts
            a = (a * invfact[j]) % p;
            a = (a * invfact[fq[i] - j]) % p;
            ans = (ans + a) % p; // Add to answer for this branch
        }

        return dp[i][m][sum] = ans; // Store result in DP array
    }

    // Main function to count balanced permutations
    int countBalancedPermutations(string num) {
        vector<ll> fq(10); // Frequency count for each digit
        ll sum = 0;
        n = size(num), len = n / 2;

        // Calculate digit frequencies and total sum
        for (char c : num) {
            fq[c - '0']++;
            sum += c - '0';
        }

        // If sum is odd, balanced split is impossible
        if (sum % 2) return 0;

        // Target sum for each half
        sum /= 2;

        // Reset DP array
        memset(dp, -1, sizeof(dp));

        // Precomputed ways to arrange half of `n` digits
        ways = (fact[len] * fact[n - len]) % p;

        // Compute balanced permutations recursively
        return util(fq, 0, sum, len);
    }
};