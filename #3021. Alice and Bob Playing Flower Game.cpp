class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddn=ceil(1.0*n/2);
        long long evenn=n/2;
        long long oddm=ceil(1.0*m/2);
        long long evenm=m/2;
        return oddn*evenm+oddm*evenn;
    }
};