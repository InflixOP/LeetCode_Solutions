class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> cnt;
        for (int x : nums)
            cnt[x]++;

        sort(nums.begin(), nums.end());
        int res = 1;
        for (int x = 0; x <= nums.back() + k; ++x) {
            int l = lower_bound(nums.begin(), nums.end(), x - k) - nums.begin();
            int r =
                upper_bound(nums.begin(), nums.end(), x + k) - nums.begin() - 1;
            int diff = r - l + 1 - cnt[x];
            res = max(res, min(diff, numOperations) + cnt[x]);
        }
        return res;
    }
};