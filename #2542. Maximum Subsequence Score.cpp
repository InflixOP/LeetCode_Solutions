class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> arr;
        for (int i = 0; i < nums1.size(); i++) {
            arr.push_back({nums2[i], nums1[i]});
        }

        sort(arr.rbegin(), arr.rend());

        priority_queue<int, vector<int>, greater<int>> pq; // min-heap
        long long mx = 0, sum = 0;

        for (auto [b, a] : arr) {
            sum += a;
            pq.push(a);

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                mx = max(mx, sum * b);
            }
        }
        return mx;
    }
};