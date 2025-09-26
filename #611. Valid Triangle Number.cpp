class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int k = (int)nums.size() - 1; k >= 2; --k) {
            int i = 0, j = k - 1;
            while (i < j) {
                if ((long long)nums[i] + nums[j] > nums[k]) { ans += j - i; --j; }
                else { ++i; }
            }
        }
        return (int)ans;
    }
};