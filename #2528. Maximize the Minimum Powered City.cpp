class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long long res = 0, left = 0, right = accumulate(stations.begin(), stations.end(), 0LL) + k;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(stations, r, mid, k)) {
                res = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return res;
    }
    
    bool check(vector<int>& stations, int r, long long minPowReq, int additionalStations) {
        int n = stations.size();
        long long windowPow = accumulate(stations.begin(), stations.begin() + r, 0LL);
        vector<int> adds(n, 0);
        for (int i = 0; i < n; i++) {
            if (i + r < n)
                windowPow += stations[i + r];
            if (windowPow < minPowReq) {
                long long need = minPowReq - windowPow;
                if (need > additionalStations)
                    return false;
                adds[min(n - 1, i + r)] += need;
                windowPow = minPowReq;
                additionalStations -= need;
            }
            if (i - r >= 0)
                windowPow -= stations[i - r] + adds[i - r];
        }
        return true;
    }
};