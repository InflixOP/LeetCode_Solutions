class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
    const long long MOD = 1e9 + 7;

    vector<long long> total(2000, 0), willActive(2000, 0), 
                      willDeactive(2000, 0), active(2000, 0);

    total[0] = 1;
    if (delay == 0) {
        active[delay] = 1;
    }

    willActive[delay] = 1;
    willDeactive[forget] = 1;

    for (int i = 1; i < n; i++) {
        long long todayAdded = (active[i - 1] + willActive[i] - willDeactive[i] + MOD) % MOD;

        total[i] = ((total[i - 1] - willDeactive[i] + MOD) % MOD + todayAdded) % MOD;

        willActive[i + delay] = (willActive[i + delay] + todayAdded) % MOD;
        willDeactive[i + forget] = (willDeactive[i + forget] + todayAdded) % MOD;

        active[i] = (active[i - 1] + willActive[i] - willDeactive[i] + MOD) % MOD;
    }

    return (int)(total[n - 1] % MOD);
}

   
};