class Solution {
    public:
        long long C(long long n){
            if(n<2) return 0;
            return n*(n-1)/2;
        }
        long long distributeCandies(int n, int limit) {
            return C(n+2)-(3*C(n-limit+1)-3*C(n-2*limit)+C(n-3*limit-1));
        }
    };