class Solution {
public:
    long long createPalindrome(long long num, bool odd) {
        string half = to_string(num);
        string revHalf = half;
        if (odd) revHalf.pop_back();  // ✅ mirror like numeric version
        reverse(revHalf.begin(), revHalf.end());
        return stoll(half + revHalf);
    }

    bool check(long long n, int b) {
        vector<int> d;
        while(n > 0){
            d.push_back(n % b);
            n /= b;
        }
        int i = 0, j = d.size() - 1;
        while (i < j) {
            if (d[i++] != d[j--]) return false;
        }
        return true;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;

        for (long long len = 1; n > 0; len *= 10) {
            for (long long i = len; n > 0 && i < len * 10; i++) {
                long long p = createPalindrome(i, true);  
                if (check(p, k)) {
                    sum += p;
                    n--;
                }
            }

            for (long long i = len; n > 0 && i < len * 10; i++) {
                long long p = createPalindrome(i, false);
                if (check(p, k)) {
                    sum += p;
                    n--;
                }
            }
        }

        return sum;
    }
};